/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:56:06 by noloupe           #+#    #+#             */
/*   Updated: 2023/09/18 18:31:43 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

void	trim_quotes(t_lexlst *lexlst, int *sq, int *dq)
{
	char		*buffer;
	int			i;
	int			j;

	while (lexlst)
	{
		buffer = ft_calloc(sizeof(char), ft_strlen(lexlst->word) + 1);
		set_ints_to_zero(&i, &j, sq, dq);
		while (lexlst->word[i])
		{
			if ((lexlst->word[i] == '\'' || lexlst->word[i] == '"') && \
				edit_quote_status(lexlst->word[i], sq, dq))
				i++;
			else
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
		i = -1;
		while (lexlst->word[++i])
		{
			if (lexlst->word[i] == '\'' || lexlst->word[i] == '"')
				edit_quote_status(lexlst->word[i], sq, dq);
			else if (is_set(lexlst->word[i], "\011\012\013\014\015\040") 
				&& *sq == 0 && *dq == 0)
			{
				buffer = ft_substr(lexlst->word, 0, i);
				add_lexlst_node(lexlst, ft_strdup(&lexlst->word[i + 1]));
				free(lexlst->word);
				lexlst->word = buffer;
				break ;
			}
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
