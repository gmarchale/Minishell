/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:09:51 by gmarchal          #+#    #+#             */
/*   Updated: 2023/08/07 18:10:06 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	count_pipes(t_lexlst *lex)
{
	int	c;

	c = 0;
	while (lex)
	{
		if (ft_strncmp(lex->word, "|", 2) == 0)
			c++;
		lex = lex->next;
	}
	return (c);
}
