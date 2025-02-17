/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aswedan <aswedan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 13:29:04 by aswedan           #+#    #+#             */
/*   Updated: 2024/09/09 12:22:38 by aswedan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*pt;
	unsigned int	i;

	pt = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (pt[i] == (unsigned char) c)
		{
			return ((void *)pt + i);
		}
		i++;
	}
	return (NULL);
}
