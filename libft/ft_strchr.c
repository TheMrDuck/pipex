/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aswedan <aswedan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:36:55 by aswedan           #+#    #+#             */
/*   Updated: 2024/09/04 09:53:01 by aswedan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int n)
{
	while (*s)
	{
		if (*s == (char)n)
			return ((char *)s);
		s++;
	}
	if (*s == (char)n)
		return ((char *)s);
	return (NULL);
}
