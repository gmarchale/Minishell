#include "../../includes/minishell.h"

int	error_msg(char c)
{
	printf("Minishell: Syntax Error near unexpected token `%c'\n", c);
	return (1);
}

int	ft_exit_failure(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}
