/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:40:21 by gmarchal          #+#    #+#             */
/*   Updated: 2023/08/31 13:40:52 by noloupe          ###   ########.fr       */
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

/*** ENUMS ***/

enum	node_error		{NODE, KEY, VALUE};
enum	env_printing	{ENV, EXPORT};
enum	token_types		{e_word, e_pipe, e_redir_in, e_redir_out, e_heredoc, e_append, e_limiter};

/*** GLOBAL ***/

t_shell *shell;

/*** MAIN ***/

char	*readline(const char *prompt);

/*** LIBFT ***/

size_t	ft_strlen(const char *s); //delete
char	*ft_strcpy(char *dest, char *src); //delete

#endif
