/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aswedan <aswedan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 13:47:08 by aswedan           #+#    #+#             */
/*   Updated: 2024/09/09 13:44:39 by aswedan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	c;
	size_t	i;

	c = 0;
	i = 0;
	if (little[0] == '\0')
		return ((char *) big);
	if (ft_strlen(big) == 0)
		return (NULL);
	while (c < len)
	{
		if (big [c] == little[i])
		{
			while (big[c + i] == little[i] && c + i < len)
			{
				if (little[i + 1] == '\0')
					return ((char *)(big + c));
				i++;
			}
			i = 0;
		}
		c++;
	}
	return (NULL);
}
