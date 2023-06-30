#include "../../includes/minishell.h"

static int	get_new_i(int i, char *cmd_line)
{
	while (cmd_line[i] && cmd_line[i] != ' ')
	{
		if (is_token(&cmd_line[i]))
		{
			i += is_token(&cmd_line[i]);
			break ;
		}
		else
		{
			while (cmd_line[i] && cmd_line[i] != ' '
				&& is_token(&cmd_line[i]) == 0)
			{
				if (cmd_line[i] == '\'' || cmd_line[i] == '\"')
					i += size_quotes(&cmd_line[i]);
				else
					i++;
			}
			break ;
		}
	}
	return (i);
}

/* 
 * Skips every spaces and uses get_new_i to handle single quotes and double quotes
 */

t_lexlst	*ft_split_lexer(char *cmd_line, t_lexlst *lexer_lst)
{
	int		i;
	int		old_i;
	char	*buff;

	i = 0;
	old_i = 0;
	while (cmd_line[i])
	{
		while (cmd_line[i])
		{
			if (cmd_line[i] != ' ')
				break ;
			i++;
		}
		if (cmd_line[i])
		{
			old_i = i;
			i = get_new_i(i, cmd_line);
			buff = ft_substr(cmd_line, old_i, i - old_i);
			lex_lstadd_back(&lexer_lst, lexlst_new(buff));
		}
	}
	return (lexer_lst);
}

/* 
 * Puts every word from command line input in a linked list of type lexlst
 * Each word being one node
 */

t_lexlst	*lexer(char *cmd_line)
{
	t_lexlst	*lexer_lst;

	lexer_lst = NULL;
	lexer_lst = ft_split_lexer(cmd_line, lexer_lst);
	return (lexer_lst);
}
