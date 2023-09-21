/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:38:43 by gmarchal          #+#    #+#             */
/*   Updated: 2023/09/21 14:22:01 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	signal_handler(int input)
{
	signal(SIGQUIT, SIG_IGN);
	if (input == 0)
		signal(SIGINT, &get_prompt);
	else if (input == 1)
	{
		signal(SIGINT, &rl_new_line);
		signal(SIGQUIT, &backslash_new_line);
	}
	else if (input == 2)
	{
		signal(SIGINT, &rl_new_line);
		signal(SIGQUIT, &sig_backslash);
	}
	else if (input == 3)
		signal(SIGINT, &sig_ctrl_c);
	else
		signal(SIGINT, &get_prompt);
}
