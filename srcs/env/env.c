/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:58:28 by gmarchal          #+#    #+#             */
/*   Updated: 2023/08/08 16:20:15 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env	*free_node_error(t_env *node, int MODE)
{
	if (MODE == KEY)
		free(node);
	else if (MODE == VALUE)
	{
		free(node->key);
		free(node);
	}
	return (NULL);
}

t_env	*create_node(char *key, char *value)
{
	t_env	*new_node;

	new_node = (t_env *)malloc(sizeof(t_env));
	if (!new_node)
		return (free_node_error(new_node, NODE));
	new_node->key = (char *)malloc(ft_strlen(key) + 1);
	if (!new_node->key)
		return (free_node_error(new_node, KEY));
	new_node->value = NULL;
	ft_strcpy(new_node->key, key);
	if (value)
	{
		new_node->value = (char *)malloc(ft_strlen(value) + 1);
		if (!new_node->value)
			return (free_node_error(new_node, VALUE));
		ft_strcpy(new_node->value, value);
	}
	new_node->next = NULL;
	return (new_node);
}

void	add_node(t_env **head, char *key, char *value)
{
	t_env	*new_node;
	t_env	*current;

	new_node = create_node(key, value);
	if (!new_node)
		return ;
	if (*head == NULL)
		*head = new_node;
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
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
		if (temp->key)
			free(temp->key);
		if (temp->value)
			free(temp->value);
		free(temp);
	}
}

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

t_env	*create_env(void)
{
	t_env 	*env;
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
