/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:05:12 by gmarchal          #+#    #+#             */
/*   Updated: 2023/09/06 18:11:32 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_lexlst
{
	char			*word;
	int				type;
	struct s_lexlst	*next;
}	t_lexlst;

typedef struct s_cmd
{
	char			**cmd;
	int				fd_in;
	int				fd_out;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_pids
{
	int				pid;
	struct s_pids	*next;
}	t_pids;

typedef struct s_shell
{
	int			exit_value;
	t_env		*env;
}	t_shell;

#endif
