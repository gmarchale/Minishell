/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:56:06 by noloupe           #+#    #+#             */
/*   Updated: 2023/08/24 19:41:06 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_size(char *key)
{
	t_env *tmp;

	tmp = shell->env;
	if (!go_to_key(&tmp, key))
	{
		free(key);
		return (0);
	}
	free(key);
	return ((int)ft_strlen(tmp->value));
}

char	*get_key(char *str)
{
	char	*key;
	int		i;

	i = 1;
	while (ft_isalnum(str[i]))
		i++;
	key = malloc(sizeof(char) * i);
	if (!key)
		exit(shell->exit_value);
	i = 1;
	while (ft_isalnum(str[i]))
	{
		key[i - 1] = str[i];
		i++;
	}
	key[i - 1] = '\0';
	return (key);
}

int	get_env_value_size(char	*str)
{
	char	*buffer;
	
	buffer = get_key(str);
	return (get_size(buffer));
}

int	skip_key(char *str)
{
	int	i;
	
	i = 1;
	while (ft_isalnum(str[i]))
		i++;
	return (i);
}

void	edit_quote_status(char c, int *sq, int *dq)
{
	if (c == '\'' && *sq == 0 && *dq == 0)
		*sq += 1;
	else if (c == '\'' && *sq == 1 && *dq == 0)
		*sq -= 1;
	else if (c == '\"' && *dq == 0 && *sq == 0)
		*dq += 1;
	else if (c == '\"' && *dq == 1 && *sq == 0)
		*dq -= 1;
}

void	add_value_to_new(char *str, char *new, int *j)
{
	t_env	*tmp;
	char	*key;
	char	*value;
	int		i;
	
	key = get_key(str);
	tmp = shell->env;
	if (!go_to_key(&tmp, key))
	{
		free(key);
		return ;
	}
	free(key);
	value = ft_strdup(tmp->value);
	if (!value)
		return ;
	i = 0;
	while (value[i])
	{
		new[*j] = value[i];
		i++;
		*j += 1;
	}
	free(value);
}

void	expand_word(t_lexlst *tmp, int count, int *sq, int *dq)
{
	char	*new;
	int		i;
	int		j;

	new = malloc(sizeof(char) * count + 1);
	if (!new)
		exit(shell->exit_value);	
	i = 0;
	j = 0;
	while (tmp->word[i])
	{
		if (tmp->word[i] == '\'' || tmp->word[i] == '"')
			edit_quote_status(tmp->word[i], sq, dq);
		if (tmp->word[i] == '$' && *sq == 0)
		{
			if (ft_isalpha(tmp->word[i + 1]))
			{
				add_value_to_new(&tmp->word[i], new, &j);
				i += skip_key(&tmp->word[i]);
			}
			else if (ft_isdigit(tmp->word[i + 1]))
				i += 2;
			else
			{
				new[j] = tmp->word[i];
				i++;
				j++;
			}
		}
		else
		{
			new[j] = tmp->word[i];
			i++;
			j++;
		}
		new[j] = '\0';
	}
	free(tmp->word);
	tmp->word = new;
}

void	expand(t_lexlst *tmp, int *sq, int *dq)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	ft_printf(1, "word = [%s]\n", tmp->word);
	while (tmp->word[i])
	{
		if (tmp->word[i] == '\'' || tmp->word[i] == '"')
			edit_quote_status(tmp->word[i], sq, dq);
		if (tmp->word[i] == '$' && *sq == 0)
		{
			if (ft_isalpha(tmp->word[i + 1]))
			{
				count += get_env_value_size(&tmp->word[i]);
				i += skip_key(&tmp->word[i]);
			}
			else if (ft_isdigit(tmp->word[i + 1]))
				i += 2;
			else
			{
				count++;
				i++;
			}
		}
		else
		{
			count++;
			i++;
		}
	}
	expand_word(tmp, count, sq, dq);
	ft_printf(1, "new word: [%s]	-	size: [%d]\n", tmp->word, (int)ft_strlen(tmp->word));
}

bool	check_expand(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return (true);
		i++;
	}
	return (false);
}

void	expander(t_lexlst *lexlst)
{
	t_lexlst	*tmp;
	int			sq;
	int			dq;

	if (!lexlst)
		return ;
	sq = 0;
	dq = 0; //check if used
	tmp = lexlst;
	while (tmp)
	{
		if (tmp->type == e_word)
		{
			if (check_expand(tmp->word))
				expand(tmp, &sq, &dq);
		}
		tmp = tmp->next;
	}
}
