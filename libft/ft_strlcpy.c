/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aswedan <aswedan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:10:46 by aswedan           #+#    #+#             */
/*   Updated: 2024/09/09 11:48:24 by aswedan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	c;

	c = 0;
	if (size == 0)
	{
		c = ft_strlen(src);
		return (c);
	}
	while (src[c] && c < size - 1)
	{
		dst[c] = src[c];
		c++;
	}
	if (c < size)
		dst[c] = '\0';
	while (src[c])
		c++;
	return (c);
}
