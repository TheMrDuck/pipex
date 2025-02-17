/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aswedan <aswedan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 14:57:55 by aswedan           #+#    #+#             */
/*   Updated: 2024/09/15 12:16:16 by aswedan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int		c;
	unsigned char		*s;
	unsigned char		*d;

	s = (unsigned char *) src;
	d = (unsigned char *) dest;
	c = 0;
	if (dest == src)
		return (dest);
	if (s < d)
	{
		while (n--)
		{
			*(d + n) = *(s + n);
		}
		return (dest);
	}
	while (c < n)
	{
		d[c] = s[c];
		c++;
	}
	return (dest);
}
