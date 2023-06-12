/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:40:21 by gmarchal          #+#    #+#             */
/*   Updated: 2023/06/12 15:49:46 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

#include "../srcs/ft_printf/ft_printf.h"
#include "../srcs/libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*** STRUCTURES ***/

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

/*** ENV ***/

void	add_node(t_env **head, char *key, char *value);
t_env	*create_node(char *key, char *value);
t_env	*env_init(char **envp);
void	free_list(t_env *head);
void	print_list(t_env *head);
void	print_env(t_env *env); //temp

/*** BUILTINS ***/

void	builtins_tester(t_env **env);
void	builtin_export(t_env **env, char *n_key, char *n_value);
void	builtin_pwd(t_env **env);
void	builtin_unset(t_env **env, char *key);

/*** LIBFT ***/

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dest, char *src);

#endif
