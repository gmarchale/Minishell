/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:42:13 by gmarchal          #+#    #+#             */
/*   Updated: 2023/09/21 14:51:28 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	create_heredoc(char *lim)
{
	int		fd;
	char	*line;

	fd = open("/tmp/heredoc.tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (!fd)
		return (-1);
	while (1)
	{
		line = readline("heredoc> ");
		if (!line)
			break ;
		else if (ft_strncmp(line, lim, ft_strlen(lim) + 1))
			ft_printf(fd, "%s\n", line);
		else
			break ;
	}
	g_shell->exit_value = 0;
	if (line)
		free(line);
	close(fd);
	fd = open("/tmp/heredoc.tmp", O_RDONLY);
	return (fd);
}
