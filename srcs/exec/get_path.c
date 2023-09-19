/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:38:02 by noloupe           #+#    #+#             */
/*   Updated: 2023/09/19 14:38:16 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*get_trimmed_path(char *str)
{
	int		i;
	char	*line;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && i < 5)
		i++;
	line = ft_strdup(&str[i]);
	return (line);
}

char	**get_path_tab(char **envp)
{
	int		i;
	char	*trimmed_line;
	char	**path_tab;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	trimmed_line = get_trimmed_path(envp[i]);
	if (!trimmed_line)
		return (NULL);
	path_tab = ft_split(trimmed_line, ':');
	free(trimmed_line);
	return (path_tab);
}

char	*get_path(char *cmd, char **envp)
{
	int		i;
	char	*path;
	char	**path_tab;

	path_tab = get_path_tab(envp);
	if (!path_tab)
		return (NULL);
	i = -1;
	while (path_tab[++i])
	{
		path = ft_strjoin(path_tab[i], "/");
		path = strjoin_free_first(path, cmd);
		if (!access(path, F_OK))
		{
			free_tab(path_tab);
			return (path);
		}
		free(path);
	}
	free_tab(path_tab);
	return (NULL);
}
