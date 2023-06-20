/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:00:52 by noloupe           #+#    #+#             */
/*   Updated: 2023/06/20 17:38:53 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_key_set(char *key)
{
	t_env *tmp;
	
	tmp = shell->env;
	return(go_to_key(&tmp, key));
}

void builtin_cd(char **str)
{
	char	*home;
	
	if (str[1] && str[2])
	{
		ft_printf(1, "minishell: cd: too many arguments\n");
		return ;
	}
	if (!str[1])
	{
		if (!is_key_set("HOME"))
		{
			ft_printf(1, "minishell: cd: HOME not set\n");
			return ;
		}
		home = dup_env_value("HOME");
		if (home && home[0] != '\0')
		{
			if (chdir(home) == -1)
				ft_printf(1, "minishell: cd: %s: No such file or directory\n", home);
			return ;
		}
	}
	if (chdir(str[1]) == -1)
				ft_printf(1, "minishell: cd: %s: No such file or directory\n", str[1]);
}
