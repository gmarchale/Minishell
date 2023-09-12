/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:42:13 by gmarchal          #+#    #+#             */
/*   Updated: 2023/09/12 14:33:38 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	create_heredoc(char *lim)
{
	int	fd;
	int i;
	char *line;

	fd = open("/tmp/minishell_heredoc.tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644); //change path
	if (!fd)
		return (-1);
	i = 1;
	while (i == 1)
	{
		line = readline("heredoc> ");
		if (ft_strncmp(line, lim, ft_strlen(lim) + 1)) //!= lim->word)
			ft_printf(fd, "%s\n", line);
		else
		{
			i = 0;
		}
	}
	free(line);
	close(fd);
	fd = open("/tmp/minishell_heredoc.tmp", O_RDONLY); // change path
	close(fd); // necessary ?
	return (fd);
}
