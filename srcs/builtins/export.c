/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:51:11 by noloupe           #+#    #+#             */
/*   Updated: 2023/06/12 15:50:28 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int export_parsing(char *n_key)
{
	int	i;

	i = 0;
	if (!ft_isalpha(n_key[i]) && n_key[i] != '_')
		return (0);
	i++;
	while (n_key[i])
	{
		if (!ft_isalnum(n_key[i]) && n_key[i] != '-')
			return (0);
		i++;
	}
	return (1);
}	

void builtin_export(t_env **env, char *n_key, char *n_value) //change arguments to struct
{
	if (!export_parsing(n_key))
	{
		ft_printf(2, "minishell: export: `%s': not a valid indentifier\n", n_key);
		return ;
	}
	add_node(env, n_key, n_value);	
}
