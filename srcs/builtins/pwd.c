/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:28:20 by noloupe           #+#    #+#             */
/*   Updated: 2023/05/25 15:41:58 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	pwd_strncmp(const char *s1, const char *s2, size_t n) //to utils
{
	unsigned int	i;

	i = 0;
	while ((unsigned char)s1[i] == (unsigned char)s2[i] && i < n)
	{
		if ((unsigned char)s1[i] == '\0' && (unsigned char)s2[i] == '\0')
			return (0);
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - s2[i]);
}

void builtin_pwd(t_env *env)
{
	while (env && pwd_strncmp(env->key, "PWD", 4))
	{
		env = env->next;
	}
	printf("%s\n", env->value);
}
