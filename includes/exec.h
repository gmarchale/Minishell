/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:17:51 by gmarchal          #+#    #+#             */
/*   Updated: 2023/07/24 14:37:52 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

/*** EXEC ***/

/* ~BUILTINS~ */

void	builtins_tester(char *line);
void	builtin_echo(char **str);
void	builtin_cd(char **str);
void	builtin_pwd(void);
void	builtin_export(char **str);
void	builtin_unset(char **str);
void	builtin_env(char **str, int MODE);
void	builtin_exit(char **str);

/* ~UTILS~ */

char	*dup_env_value(char *key);
int		go_to_key(t_env **tmp, char *key);
int		key_check(char *key, char *word);

void	execution(t_cmd *cmd_l);
int		is_solo_builtin(t_cmd *cmd_l);
int		is_builtin(char	*cmd);

#endif
