/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:03:28 by gmarchal          #+#    #+#             */
/*   Updated: 2023/06/16 14:19:15 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
#define PARSER_H

/*** ENV ***/

void	add_node(t_env **head, char *key, char *value);
t_env	*create_node(char *key, char *value);
t_env	*env_init(char **envp);
void	free_list(t_env *head);
void	print_list(t_env *head);
void	print_env(t_env *env); //temp

#endif
