#include "../../includes/minishell.h"

t_lexlst	*parser(char *cmd_line) //, int *pipes)
{
	t_lexlst	*lexer_lst;

	lexer_lst = NULL;
	if (checker_quotes(cmd_line, 0, 0))
		return (lexer_lst);
	if (check_token(cmd_line)) //creer fonction check token
		return (lexer_lst);
	parse_list(); //creer fonction qui prend la lex list et la met dans une liste chainee t_cmd
	return (lexer_lst);
}
