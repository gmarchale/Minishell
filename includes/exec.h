/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:17:51 by gmarchal          #+#    #+#             */
/*   Updated: 2023/09/19 14:50:56 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

/*** EXEC ***/

/* ~BUILTINS~ */

void	builtin_echo(char **str);
void	builtin_cd(char **str);
void	builtin_pwd(void);
void	builtin_export(char **str);
void	builtin_unset(char **str);
void	builtin_env(char **str, int MODE);
void	builtin_exit(char **str);

/* ~EXEC~ */

void	add_pid_to_list(t_pids **pids, int pid);
void	change_fds(t_cmd *cmdlst);
void	close_first_pipe(t_cmd *cmdlst, int pipes[2][2]);
void	close_pipes(t_cmd *cmdlst, int pipes[2][2]);
char	*dup_env_value(char *key);
char	**env_to_list(void);
void	exec_builtin(t_cmd *cmdlst);
void	exec_child_builtin(t_cmd *cmdlst);
void	execution(t_cmd *cmd_l);
void	free_pids_list(t_pids *pids);
void	free_tab(char **tab);
char	*get_path(char *cmd, char **envp);
int		go_to_key(t_env **tmp, char *key);
void	init_pipes(int pipes[2][2]);
int		is_solo_builtin(t_cmd *cmd_l);
int		is_builtin(char	*cmd);
int		key_check(char *key, char *word);
void	last_link(t_cmd *cmdlst, int pipes[2]);
void	link_pipe(t_cmd *cmdlst, int pipes[2][2]);
void	perror_exit(char *str, int value);
void	restore_fds(int base_in, int base_out);
void	swap_pipes(int pipes[2][2]);
void	wait_pids(t_pids *pids);

#endif
