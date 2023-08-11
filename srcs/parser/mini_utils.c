/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:07:25 by gmarchal          #+#    #+#             */
/*   Updated: 2023/08/11 15:07:28 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	error_msg(char c)
{
	printf("Minishell: Syntax Error near unexpected token `%c'\n", c);
	return (1);
}

int	ft_exit_failure(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}
