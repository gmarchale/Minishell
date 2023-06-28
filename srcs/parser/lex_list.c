#include "../../includes/minishell.h"

int	lex_lstsize(t_lexlst *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_lexlst	*lex_lstlast(t_lexlst *lst, int stop)
{
	int	s;
	int	i;

	if (!lst)
		return (0);
	i = 0;
	s = lex_lstsize(lst);
	while (lst && i < s - 1 - stop)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}

void	lex_lstadd_back(t_lexlst **lst, t_lexlst *new)
{
	t_lexlst	*last;

	if (!lst || !new)
		return ;
	if (new)
	{
		if (!*lst) //changer qq chose jai oublie 
		{
			*lst = new;
			return ;
		}
	}
	last = lex_lstlast(*lst, 0);
	last->next = new;
}
