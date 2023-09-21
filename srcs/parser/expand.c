/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:27:12 by noloupe           #+#    #+#             */
/*   Updated: 2023/09/21 13:17:02 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	expand_word(t_lexlst *tmp, int count, int *sq, int *dq)
{
	char	*new;
	int		i;
	int		j;

	new = malloc(sizeof(char) * count + 1);
	if (!new)
		exit(g_shell->exit_value);
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

void	expand_types(t_lexlst **tmp, int *i, int *count)
{
	char	*str;

	if ((*tmp)->word[*i + 1] == '?')
	{
		str = ft_itoa(g_shell->exit_value);
		*count += ft_strlen(str);
		free(str);
		*i += 2;
	}
	else if (ft_isalpha((*tmp)->word[*i + 1]))
	{
		*count += get_env_value_size(&(*tmp)->word[*i]);
		*i += skip_key(&(*tmp)->word[*i]);
	}
	else if (ft_isdigit((*tmp)->word[*i + 1]))
		*i += 2;
	else
		increment_both_int(i, count);
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
			expand_types(&tmp, &i, &count);
		else
			increment_both_int(&i, &count);
	}
	expand_word(tmp, count, sq, dq);
}
