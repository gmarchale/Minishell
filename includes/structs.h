/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:05:12 by gmarchal          #+#    #+#             */
/*   Updated: 2023/06/29 16:26:41 by gmarchal         ###   ########.fr       */
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

typedef struct s_redir
{
	char			*key;
	int				mode;
	struct s_redir	*next;
}			t_redir;

typedef struct s_lexlst
{
	char			*word;
	struct s_lexlst	*next;
}	t_lexlst;

typedef struct s_cmd
{
	char			**cmd;
	int				(*builtin)(struct s_cmd *);
	char			*rd_in;
	char			*rd_out;
	//t_env			*head; //deja dans le globale
	struct s_cmd	*next;
	// int				exit_status; // dans le globale aussi
	int				index;
	char			*cwd;
}	t_cmd;

typedef struct s_shell
{
	int	exit_value;
	t_env *env;
}	t_shell;

#endif
