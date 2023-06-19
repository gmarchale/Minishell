/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:17:51 by gmarchal          #+#    #+#             */
/*   Updated: 2023/06/19 13:55:01 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

/*** EXEC ***/

void	builtins_tester(char *line);
void	builtin_echo(char **str);
void	builtin_env(char **str);
void	builtin_exit(char **str);
void	builtin_export(char **str);
void	builtin_pwd(t_env **env);
void	builtin_unset(t_env **env, char *key);
int		key_check(char *key, char *word);

#endif
