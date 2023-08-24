/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexlst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:00:05 by noloupe           #+#    #+#             */
/*   Updated: 2023/08/14 15:05:58 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_lexlst(t_lexlst *lexlst)
{
	if (!lexlst)
		return ;
	while (lexlst)
	{
		free(lexlst->word);
		lexlst = lexlst->next;
	}
	free(lexlst);
}
