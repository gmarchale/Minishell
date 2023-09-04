/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <gmarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:40:21 by gmarchal          #+#    #+#             */
/*   Updated: 2023/09/04 17:43:49 by gmarchal         ###   ########.fr       */
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
# include "structs.h"
# include "parser.h"
# include "exec.h"
# include <signal.h>
# include <fcntl.h>

/*** ENUMS ***/

enum	node_error		{NODE, KEY, VALUE};
enum	env_printing	{ENV, EXPORT};

/*** GLOBAL ***/

t_shell *shell;

/*** MAIN ***/

char	*readline(const char *prompt);

/*** LIBFT ***/

size_t	ft_strlen(const char *s); //delete
char	*ft_strcpy(char *dest, char *src); //delete

/*** Signals ***/

void    rl_replace_line(char *s, int n); //necessaire sinon le signal fonctionne pas (ask bruno)
void	signal_handler(int input);

/*** Heredoc ***/
int	create_heredoc(char *lim); //(t_lexlst lim)

#endif
