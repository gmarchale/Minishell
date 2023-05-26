/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin_free1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:39:28 by noloupe           #+#    #+#             */
/*   Updated: 2023/03/30 11:33:02 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strjoin_free1(char *s1, char const *s2)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		++i;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		++i;
		++j;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}
