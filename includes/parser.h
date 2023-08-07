/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <gmarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:03:28 by gmarchal          #+#    #+#             */
/*   Updated: 2023/08/07 18:10:54 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

/*** ENV ***/

void	add_node(t_env **head, char *key, char *value);
t_env	*create_node(char *key, char *value);
t_env	*env_init(char **envp);
void	free_list(t_env *head);
void	print_list(t_env *head);
void	print_env(t_env *env); //temp

/*** MINI_UTILS ***/
int	error_msg(char c);
int	ft_exit_failure(char *str);

/*** LEXER ***/
int	check_token(char *line);
int	is_token(char *str);
int	size_quotes(const char *str);
t_lexlst	*lexer(char *cmd_line);

/*** LEXER_UTILS ***/

int	checker_quotes(char *line, int s, int d);
int	check_token_ends(char *line);
int	skip_quotes(char *line, int *dq);

/*** LEX_LIST ***/

int	lex_lstsize(t_lexlst *lst);
t_lexlst	*lex_lstlast(t_lexlst *lst, int stop);
void	lex_lstadd_back(t_lexlst **lst, t_lexlst *new);
t_lexlst	*lexlst_new(void *content);
void	lexlst_clear(t_lexlst **lst);

/*** PARSER_UTILS ***/
int	count_pipes(t_lexlst *lex);

#endif
