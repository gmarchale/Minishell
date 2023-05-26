/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:28:50 by noloupe           #+#    #+#             */
/*   Updated: 2023/03/24 13:53:47 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*calloc;

	calloc = malloc(count * size);
	if (!calloc)
		return (NULL);
	ft_bzero(calloc, count * size);
	return (calloc);
}
