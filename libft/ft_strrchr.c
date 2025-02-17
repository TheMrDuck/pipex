/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aswedan <aswedan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:09:27 by aswedan           #+#    #+#             */
/*   Updated: 2024/09/15 12:11:32 by aswedan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		uc;
	const char	*r;

	uc = (char) c;
	r = 0;
	while (*s != '\0')
	{
		if (*s == uc)
			r = s;
		s++;
	}
	if (uc == '\0')
		r = s;
	return ((char *)r);
}
