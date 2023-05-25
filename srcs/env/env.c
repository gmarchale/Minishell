/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:58:28 by gmarchal          #+#    #+#             */
/*   Updated: 2023/05/25 13:46:49 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env *env_init(char **envp)
{
	t_env	*env;
	int		i; 
	char	*env_var;
	
	env = NULL;
	i = 0;
	env_var = envp[i];
	while (env_var)
	{
		add_env_back(&env, new_env_node(env_var));
		env_var = envp[i];
		i++;
	}
	return (env);
}

t_env *new_env_node(char *env_var)
{
	t_env *new;
	
	if (!env_var)
		return (NULL);
	new = malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->key = strtok(env_var, "=");
	new->value = strtok(NULL, "=");
	new->next = NULL;
	return (new);
}

void add_env_back(t_env **env, t_env *new)
{
	t_env *last;

	if (!new)
		return ;
	if (!*env)
		*env = new;
	else
	{
		last = last_env(*env);
		last->next = new; 
	}
}

t_env *last_env(t_env *env)
{
	if (!env)
		return (NULL);
	while (env->next)
		env = env->next;
	return (env);
}

void print_env(t_env *env) //temp
{
	t_env *env_cpy;
	int i;

	env_cpy = env;
	i = 0;
	while(env_cpy)
	{
		printf("--- NODE %d ---\n", i);
		printf("Key:	%s\n", env_cpy->key);
		printf("Value:	%s\n", env_cpy->value);
		printf("---------------\n\n");
		env_cpy = env_cpy->next;
		i++;
	}
}
