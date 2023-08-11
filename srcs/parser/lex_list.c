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
		if (!*lst)
		{
			*lst = new;
			return ;
		}
	}
	last = lex_lstlast(*lst, 0);
	last->next = new;
}

t_lexlst	*lexlst_new(void *content)
{
	t_lexlst	*ele;

	ele = NULL;
	if (!content)
		return (ele);
	ele = malloc(sizeof(t_lexlst));
	if (!ele)
		ft_exit_failure("malloc");
	ele->word = content;
	ele->next = NULL;
	return (ele);
}

void	lexlst_clear(t_lexlst **lst)
{
	t_lexlst	*tmp;

	tmp = NULL;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp->word);
		free(tmp);
	}
}
