/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:58:28 by gmarchal          #+#    #+#             */
/*   Updated: 2023/06/05 15:16:33 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env	*create_node(char *key, char *value)
{
	t_env	*new_node;

	new_node = (t_env *)malloc(sizeof(t_env));
	new_node->key = (char *)malloc(strlen(key) + 1);
	new_node->value = (char *)malloc(strlen(value) + 1);
	strcpy(new_node->key, key);
	strcpy(new_node->value, value);
	new_node->next = NULL;
	return (new_node);
}

void	add_node(t_env **head, char *key, char *value)
{
	t_env	*new_node;
	t_env	*current;

	new_node = create_node(key, value);
	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		current = *head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_node;
	}
}

void	print_list(t_env *head)
{
	t_env	*current;

	current = head;
	while (current != NULL)
	{
		printf("%s=%s\n", current->key, current->value);
		current = current->next;
	}
}

void	free_list(t_env *head)
{
	t_env	*temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp->key);
		free(temp->value);
		free(temp);
	}
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
	return (head);
}

void	print_env(t_env *env) //temp
{
	t_env	*env_cpy;
	int		i;

	env_cpy = env;
	i = 0;
	while (env_cpy)
	{
		printf("--- NODE %d ---\n", i);
		printf("Key:	%s\n", env_cpy->key);
		printf("Value:	%s\n", env_cpy->value);
		printf("---------------\n\n");
		env_cpy = env_cpy->next;
		i++;
	}
}
/*
int	main(int argc, char **argv, char **envp)
{
	t_env	*linked_list;
	(void)argc; (void)argv;

	linked_list = env_init(envp);
	print_env(linked_list);
    print_list(linked_list);
	free_list(linked_list);
	return (0);
}
*/
