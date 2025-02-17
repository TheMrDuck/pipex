/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aswedan <aswedan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:29:25 by aswedan           #+#    #+#             */
/*   Updated: 2024/09/15 11:47:07 by aswedan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	c;
	unsigned int	j;
	unsigned int	i;

	c = 0;
	j = 0;
	i = 0;
	while (dest[c] != '\0')
		c++;
	while (src[j] != '\0')
		j++;
	if (size <= c)
		return (size + j);
	while (src[i] != '\0' && (c + i) < (size - 1))
	{
		dest[c + i] = src[i];
		i++;
	}
	dest[c + i] = '\0';
	return (c + j);
}
