/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:00:52 by noloupe           #+#    #+#             */
/*   Updated: 2023/09/15 17:40:35 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_key_set(char *key)
{
	t_env	*tmp;

	tmp = shell->env;
	return (go_to_key(&tmp, key));
}

void	change_env_pwd(void)
{
	t_env	*pwd;
	t_env	*old_pwd;

	old_pwd = shell->env;
	pwd = shell->env;
	if (go_to_key(&pwd, "PWD"))
	{
		if (go_to_key(&old_pwd, "OLDPWD"))
		{
			free(old_pwd->value);
			old_pwd->value = NULL;
			if (pwd->value)
				old_pwd->value = ft_strdup(pwd->value);
		}
		if (pwd->value)
			free(pwd->value);
		pwd->value = getcwd(NULL, 0);
		return ;
	}
	if (go_to_key(&old_pwd, "OLDPWD"))
	{
		free(old_pwd->value);
		old_pwd->value = NULL;
	}
}

void	go_to_home(void)
{
	char	*home;

	if (!is_key_set("HOME"))
	{
		ft_printf(1, "minishell: cd: HOME not set\n");
		return ;
	}
	home = dup_env_value("HOME");
	if (home)
	{
		if (home[0] != '\0' && chdir(home) == -1)
			ft_printf(1, "minishell: cd: %s: No such file or directory\n", home);
	}
	else
		ft_printf(1, "minishell: cd: HOME not set\n");
}

void	builtin_cd(char **str)
{
	if (str[1] && str[2])
	{
		ft_printf(1, "minishell: cd: too many arguments\n");
		return ;
	}
	if (!str[1])
	{
		go_to_home();
		change_env_pwd();
		return ;
	}
	if (chdir(str[1]) == -1)
	{
		ft_printf(1, "minishell: cd: %s: No such file or directory\n", str[1]);
		return ;
	}
	change_env_pwd();
}
