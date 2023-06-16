/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:40:21 by gmarchal          #+#    #+#             */
/*   Updated: 2023/06/16 11:04:19 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

# include "../srcs/ft_printf/ft_printf.h"
# include "../srcs/libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>

/*** STRUCTURES ***/

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_shell
{
	t_env *env;
}	t_shell;

t_shell *shell;

/*** MAIN ***/

char	*readline(const char *prompt);

/*** ENV ***/

void	add_node(t_env **head, char *key, char *value);
t_env	*create_node(char *key, char *value);
t_env	*env_init(char **envp);
void	free_list(t_env *head);
void	print_list(t_env *head);
void	print_env(t_env *env); //temp

/*** EXEC ***/

void	builtins_tester(char *line);
void	builtin_echo(char **str);
void	builtin_env(t_env **env);
void	builtin_exit(int arg);
void	builtin_export(t_env **env, char *n_key, char *n_value);
void	builtin_pwd(t_env **env);
void	builtin_unset(t_env **env, char *key);
int		key_check(char *key, char *word);

/*** LIBFT ***/

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dest, char *src);

#endif
