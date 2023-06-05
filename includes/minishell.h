/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:40:21 by gmarchal          #+#    #+#             */
/*   Updated: 2023/06/05 15:48:59 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*** STRUCTURES ***/

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

/*** ENV ***/

t_env *env_init(char **envp);
t_env *new_env_node(char *env_var);
void add_env_back(t_env **env, t_env *new);
t_env *last_env(t_env *env);
void print_env(t_env *env); //temp

/*** BUILTINS ***/

/*** LIBFT ***/
size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dest, char *src);

#endif
