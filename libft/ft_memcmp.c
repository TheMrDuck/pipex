/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aswedan <aswedan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 13:34:27 by aswedan           #+#    #+#             */
/*   Updated: 2024/09/09 15:12:17 by aswedan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int		c;
	unsigned char		*i;
	unsigned char		*j;

	i = (unsigned char *) s1;
	j = (unsigned char *) s2;
	c = 0;
	if (n == 0)
		return (0);
	while (i[c] == j[c] && c < n - 1)
		c++;
	return (i[c] - j[c]);
}
