/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aswedan <aswedan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 14:46:54 by aswedan           #+#    #+#             */
/*   Updated: 2024/09/15 12:15:54 by aswedan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int		c;
	unsigned char		*s;
	unsigned char		*d;

	if (!dest && !src)
		return (NULL);
	c = 0;
	s = (unsigned char *) src;
	d = (unsigned char *) dest;
	while (c != n)
	{
		d[c] = s[c];
		c++;
	}
	return (d);
}
