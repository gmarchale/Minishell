/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:03:28 by gmarchal          #+#    #+#             */
/*   Updated: 2023/09/19 14:58:13 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

/*** ENV ***/

void		add_node(t_env **head, char *key, char *value);
t_env		*create_env(void);
t_env		*create_node(char *key, char *value);
t_env		*env_init(char **envp);
void		free_env_list(t_env *head);
t_env		*create_env(void);

/*** MINI_UTILS ***/
int			error_msg(char c);
int			ft_exit_failure(char *str);
void		free_cmdlst(t_cmd *cmdlst);

/*** LEXER ***/
int			check_token(char *line);
int			is_token(char *str);
int			size_quotes(const char *str);
t_lexlst	*lexer(char *cmd_line);

/*** LEXER_UTILS ***/

int			checker_quotes(char *line);
int			check_token_ends(char *line);
int			skip_quotes(char *line, int *dq);

/*** LEX_LIST ***/

int			lex_lstsize(t_lexlst *lst);
t_lexlst	*lex_lstlast(t_lexlst *lst, int stop);
void		lex_lstadd_back(t_lexlst **lst, t_lexlst *new);
t_lexlst	*lexlst_new(void *content);
void		lexlst_clear(t_lexlst **lst);

/*** PARSER_UTILS ***/

int			count_pipes(t_lexlst *lex);

/*** PARSER ***/

bool		is_set(char c, char *charset);
int 		parser(t_lexlst *lexlst);

/*** EXPANDER ***/

bool		check_expand(char *str);
t_cmd		*cmd_new_node(void);
void		copy_and_increment(t_lexlst *tmp, char *new, int *i, int *j);
void		copy_key_value(t_lexlst *tmp, char *new, int *i, int *j);
bool		edit_quote_status(char c, int *sq, int *dq);
void		expand(t_lexlst *tmp, int *sq, int *dq);
void		expander(t_lexlst *lexlst);
int			get_env_value_size(char	*str);
int			get_fd(char *str, int type);
char		*get_key(char *str);
void		increment_both_int(int *i, int *j);
t_cmd		*lst_to_cmd(t_lexlst *lst);
void		set_ints_to_zero(int *i, int *j, int *sq, int *dq);
int			skip_key(char *str);
int			type_pipe(t_cmd **cmd, int *i, int *stop);
void		type_redir_in(t_cmd **cmd, t_lexlst **lexlst);
void		type_redir_out(t_cmd **cmd, t_lexlst **lexlst);
void		type_word(t_cmd **cmd, t_lexlst **lexlst, int *i);

#endif
