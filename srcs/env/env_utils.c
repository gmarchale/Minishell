/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:53:37 by noloupe           #+#    #+#             */
/*   Updated: 2023/09/19 14:53:55 by noloupe          ###   ########.fr       */
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

void	free_env_list(t_env *head)
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
