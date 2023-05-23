/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:48:06 by gmarchal          #+#    #+#             */
/*   Updated: 2023/05/23 17:12:14 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(int argc, char **argv, char **envp)
{
	t_env env;

	int	i = 0;
	char	*env_variable = envp[i];

	while (env_variable != NULL)
	{
		env.next = NULL;
		printf("%s\n", env_variable);
		env.key = strtok(env_variable, "=");
		env.value = strtok(NULL, "=");
		printf("Key = %s\n", env.key);
		printf("Value = %s\n\n", env.value);
		env.next = NULL;
		i++;
		env_variable = envp[i];
	}
	return (0);
}
