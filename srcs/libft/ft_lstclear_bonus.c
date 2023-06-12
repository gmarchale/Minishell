/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:34:50 by noloupe           #+#    #+#             */
/*   Updated: 2022/10/14 11:53:59 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;

	if (!lst || !*del)
		return ;
	while (*lst)
	{
		node = *lst;
		*lst = (*lst)->next;
		del(node->content);
		free(node);
	}
	lst = NULL;
}
