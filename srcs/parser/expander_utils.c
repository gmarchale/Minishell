/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:03:24 by noloupe           #+#    #+#             */
/*   Updated: 2023/09/18 18:29:52 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	set_ints_to_zero(int *i, int *j, int *sq, int *dq)
{
	*i = 0;
	*j = 0;
	*sq = 0;
	*dq = 0;
}

bool	check_expand(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return (true);
		i++;
	}
	return (false);
}

int	skip_key(char *str)
{
	int	i;

	i = 1;
	while (ft_isalnum(str[i]))
		i++;
	return (i);
}

bool	edit_quote_status(char c, int *sq, int *dq)
{
	if (c == '\'' && *sq == 0 && *dq == 0)
		*sq += 1;
	else if (c == '\'' && *sq == 1 && *dq == 0)
		*sq -= 1;
	else if (c == '\"' && *dq == 0 && *sq == 0)
		*dq += 1;
	else if (c == '\"' && *dq == 1 && *sq == 0)
		*dq -= 1;
	else
		return (false);
	return (true);
}
