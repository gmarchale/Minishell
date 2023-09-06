/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:56:06 by noloupe           #+#    #+#             */
/*   Updated: 2023/08/28 14:48:50 by noloupe          ###   ########.fr       */
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

bool	edit_quote_status(char c, int *sq, int *dq)
{
	if (c == '\'' && *sq == 0 && *dq == 0)
		*sq += 1;
	else if (c == '\'' && *sq == 1 && *dq == 0)
		*sq -= 1;
	else if (c == '\"' && *dq == 0 && *sq == 0)
		*dq += 1;
	else if (c == '\"' && *dq == 1 && *sq == 0)
		*dq -= 1;
	else
		return (false);
	return (true);
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

void	increment_both_int(int *i, int *j)
{
	if (!i || !j)
		return ;
	*i += 1;
	*j += 1;
}

void	copy_and_increment(t_lexlst *tmp, char *new, int *i, int *j)
{
	new[*j] = tmp->word[*i];
	increment_both_int(i, j);
}

void	copy_key_value(t_lexlst *tmp, char *new, int *i, int *j)
{
	if (ft_isalpha(tmp->word[*i + 1]))
	{
		add_value_to_new(&tmp->word[*i], new, j);
		*i += skip_key(&tmp->word[*i]);
	}
	else if (ft_isdigit(tmp->word[*i + 1]))
		*i += 2;
	else
		copy_and_increment(tmp, new, i, j);
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
			copy_key_value(tmp, new, &i, &j);
		else
			copy_and_increment(tmp, new, &i, &j);
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
				increment_both_int(&i, &count);
		}
		else
			increment_both_int(&i, &count);
	}
	expand_word(tmp, count, sq, dq);
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

void	add_lexlst_node(t_lexlst *lexlst, char *str)
{
	t_lexlst	*new;
	t_lexlst	*save;

	save = lexlst->next;
	new = lexlst_new(ft_strdup(str));
	if (!new)
		return ;
	lexlst->next = new;
	new->next = save;
}

void	set_ints_to_zero(int *i, int *j, int *sq, int *dq)
{
	*i = 0;
	*j = 0;
	*sq = 0;
	*dq = 0;
}

void	trim_quotes(t_lexlst *lexlst, int *sq, int *dq)
{
	char		*buffer;
	int			i;
	int			j;

	while (lexlst)
	{
		buffer = ft_calloc(sizeof(char), ft_strlen(lexlst->word));
		set_ints_to_zero(&i, &j, sq, dq);
		while (lexlst->word[i])
		{
			if (lexlst->word[i] == '\'' || lexlst->word[i] == '"')
			{
				while (edit_quote_status(lexlst->word[i], sq, dq))
					i++;
			}
			copy_and_increment(lexlst, buffer, &i, &j);
		}
		buffer[j] = '\0';
		free(lexlst->word);
		lexlst->word = ft_strdup(buffer);
		free(buffer);
		lexlst = lexlst->next;
	}
}

void	remove_quotes_and_split_expanded(t_lexlst *lexlst, int *sq, int *dq)
{
	t_lexlst	*save;
	char		*buffer;
	int			i;

	save = lexlst;
	while (lexlst)
	{
		i = 0;
		while (lexlst->word[i])
		{
			if (lexlst->word[i] == '\'' || lexlst->word[i] == '"')
				edit_quote_status(lexlst->word[i], sq, dq);
			else if (is_set(lexlst->word[i], "\011\012\013\014\015\040") && *sq == 0 && *dq == 0)
			{
				buffer = ft_substr(lexlst->word, 0, i);
				add_lexlst_node(lexlst, ft_strdup(&lexlst->word[i + 1]));
				free(lexlst->word);
				lexlst->word = buffer;
				break ;
			}
			i++;
		}
		lexlst = lexlst->next;
	}
	trim_quotes(save, sq, dq);
}

void	expander(t_lexlst *lexlst)
{
	t_lexlst	*save;
	int			sq;
	int			dq;

	if (!lexlst)
		return ;
	sq = 0;
	dq = 0;
	save = lexlst;
	while (lexlst)
	{
		if (lexlst->type == e_word)
		{
			if (check_expand(lexlst->word))
				expand(lexlst, &sq, &dq);
		}
		lexlst = lexlst->next;
	}
	remove_quotes_and_split_expanded(save, &sq, &dq);
}
