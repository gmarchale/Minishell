/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:40:21 by gmarchal          #+#    #+#             */
/*   Updated: 2023/06/16 14:20:48 by gmarchal         ###   ########.fr       */
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
# include "structs.h"
# include "parser.h"
# include "exec.h"

/*** GLOBAL ***/

t_shell *shell;

/*** MAIN ***/

char	*readline(const char *prompt);

/*** LIBFT ***/

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dest, char *src);

#endif
