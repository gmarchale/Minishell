/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:17:51 by gmarchal          #+#    #+#             */
/*   Updated: 2023/06/16 14:18:48 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

/*** EXEC ***/

void	builtins_tester(char *line);
void	builtin_echo(char **str);
void	builtin_env(t_env **env);
void	builtin_exit(int arg);
void	builtin_export(t_env **env, char *n_key, char *n_value);
void	builtin_pwd(t_env **env);
void	builtin_unset(t_env **env, char *key);
int		key_check(char *key, char *word);

#endif
