/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:40:21 by gmarchal          #+#    #+#             */
/*   Updated: 2023/09/21 14:22:57 by noloupe          ###   ########.fr       */
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
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include "structs.h"
# include "parser.h"
# include "exec.h"
# include <signal.h>
# include <fcntl.h>

/*** ENUMS ***/

enum	e_node_error		{e_node, e_key, e_value};
enum	e_env_printing		{e_env, e_export};
enum	e_token_types		{e_word, e_pipe, e_redir_in,\
							e_redir_out, e_heredoc, e_append, e_limiter};

/*** GLOBAL ***/

t_shell	*g_shell;

/*** MAIN ***/

char	*readline(const char *prompt);

/*** LIBFT ***/

char	*ft_strcpy(char *dest, char *src);

/*** Signals ***/

void	backslash_new_line(int sig);
void	get_prompt(int sig);
void	rl_new_line(int sig);
void	rl_replace_line(char *s, int n);
void	signal_handler(int input);
void	sig_backslash(int sig);
void	sig_ctrl_c(int sig);

/*** Heredoc ***/
int		create_heredoc(char *lim);

#endif
