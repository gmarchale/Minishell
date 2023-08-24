/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexlst_to_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:33:00 by noloupe           #+#    #+#             */
/*   Updated: 2023/08/18 15:58:42 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	is_set(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (true);
		i++;
	}
	return (false);
}

// int	expand_var(char *needle, char **buffer)
// {
// 	t_env	*tmp;
// 	char	*str;
// 	int		count;
// 	int		i;

// 	count = 0;
// 	i = -1;
// 	while (!is_set(needle[++i], "\"\040\011\012\013\014\015"))
// 		++count;
// 	str = malloc(sizeof(char) * count + 1);
// 	if (!str)
// 		exit(shell->exit_value);
// 	i = -1;
// 	while (++i < count)
// 	{
// 		str[i] = needle[i];
// 	}
// 	str[i] = '\0';
// 	tmp = shell->env;
// 	if (go_to_key(&tmp, str))
// 	{
// 		if (tmp->value)
// 			*buffer = strjoin_free_first(*buffer, tmp->value);
// 	}
// 	free(str);
// 	return ((int)ft_strlen(tmp->value));
// }

// int	expand_quotes(t_lexlst *lexlst)
// {
// 	char	*buffer;
// 	int		open;
// 	int		i;
// 	int		j;

// 	if (!lexlst->word)
// 		return (0);
// 	buffer = ft_calloc(sizeof(char), ft_strlen(lexlst->word) + 1);
// 	if (!buffer)
// 		exit(shell->exit_value);
// 	ft_bzero(buffer, ft_strlen(lexlst->word) + 1);
// 	open = 0;
// 	i = 0;
// 	j = 0;
// 	while (lexlst->word[i])
// 	{
// 		// ft_printf(1, "CHAR: %c\n", lexlst->word[i]);
// 		// ft_printf(1, "BUFFER: %s\n", buffer);
// 		if (open == 0 && lexlst->word[i] == '\'')
// 			open = 1;
// 		else if (open == 0 && lexlst->word[i] =='"')
// 			open = 2;
// 		else if (open == 1 && lexlst->word[i] == '\'')
// 			open = 0;
// 		else if (open == 2 && lexlst->word[i] == '"')
// 			open = 0;
// 		else
// 		{
// 			if (lexlst->word[i] == '$' && is_set(lexlst->word[i + 1], "\"\040\011\012\013\014\015\000"))
// 				buffer[j] = lexlst->word[i];
// 			else if (open == 2 && lexlst->word[i] == '$')
// 			{
// 				i++;
// 				j += expand_var(&lexlst->word[i], &buffer);
// 				while (lexlst->word[i] && !is_set(lexlst->word[i], "\040\011\012\013\014\015"))
// 				{
// 					if (lexlst->word[i] == '"')
// 						open = 0;
// 					i++;
// 				}
// 			}
// 			else
// 				buffer[j] = lexlst->word[i];
// 			j++;
// 		}
// 		i++;
// 	}
// 	free(lexlst->word);
// 	lexlst->word = ft_strdup(buffer);
// 	free(buffer);
// 	if (open)
// 		return (-1);
// 	return (i);
// }

// int	check_expand_quotes(t_lexlst *lexlst)
// {
// 	int	i;
// 	int	ret;

// 	// if (!lexlst)
// 	// 	return (0);
// 	while (lexlst)
// 	{
// 		// ft_printf(2, "%s\n", lexlst->word);
// 		i = 0;
// 		while (lexlst->word[i])
// 		{
// 			if (lexlst->word[i] == '\'' || lexlst->word[i] == '"')
// 			{
// 				//ft_printf(1, "[%c]: %d\n", lexlst->word[i], i);
// 				ret = expand_quotes(lexlst);
// 				if (ret == -1)
// 				{
// 					ft_printf(2, "Error while expanding quote\n");
// 					return (0);
// 				}
// 				i += ret;
// 			}
// 			i++;
// 		}
// 		lexlst = lexlst->next;
// 	}
// 	return (1);
// }

// void	lexlst_to_cmd(t_lexlst *lexlst)
// {
// 	 if (!lexlst)
// 	 	return ;
// 	if (!check_expand_quotes(lexlst))
// 		return ;
// }