/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:28:20 by noloupe           #+#    #+#             */
/*   Updated: 2023/06/24 09:59:54 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void builtin_pwd(void)
{
	char *str;

	str = getcwd(NULL, 0);
	if (str)
		printf("%s\n", str);
	else
		perror("pwd");
	free(str);
}
