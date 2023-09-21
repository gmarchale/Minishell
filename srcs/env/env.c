/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:58:28 by gmarchal          #+#    #+#             */
/*   Updated: 2023/09/19 14:55:26 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	increment_shlvl(t_env *env)
{
	t_env	*cpy;
	int		shlvl;
	char	*new;

	cpy = env;
	if (go_to_key(&cpy, "SHLVL"))
	{
		shlvl = ft_atoi(cpy->value);
		++shlvl;
		new = ft_itoa(shlvl);
		free(cpy->value);
		cpy->value = new;
	}
	else
		ft_printf(2, "Error: could not increment SHLVL\n");
}

t_env	*env_init(char **envp)
{
	char	*env;
	char	*key;
	char	*value;
	int		i;
	t_env	*head;

	head = NULL;
	i = 0;
	while (envp[i] != NULL)
	{
		env = strdup(envp[i]);
		key = env;
		value = strchr(env, '=');
		if (value != NULL)
		{
			*value = '\0';
			value++;
			add_node(&head, key, value);
		}
		free(env);
		i++;
	}
	increment_shlvl(head);
	return (head);
}

t_env	*create_env(void)
{
	t_env	*env;
	char	*tmp;

	env = NULL;
	add_node(&env, "OLDPWD", NULL);
	tmp = getcwd(NULL, 0);
	if (!tmp)
		exit (1);
	add_node(&env, "PWD", tmp);
	free(tmp);
	add_node(&env, "SHLVL", "1");
	return (env);
}
