/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aswedan <aswedan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:51:31 by aswedan           #+#    #+#             */
/*   Updated: 2024/09/09 15:49:25 by aswedan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		sc;
	int		ec;
	char	*ts;

	if (!s1 || !set)
		return (NULL);
	sc = 0;
	ec = ft_strlen(s1) -1;
	while (ft_strchr(set, s1[sc]) && sc <= ec)
		sc++;
	if (sc > ec)
		return (ft_strdup(""));
	while (ft_strchr(set, s1[ec]) && ec >= 0)
		ec--;
	ts = malloc(ec - sc + 2);
	if (!ts)
		return (NULL);
	ft_strlcpy(ts, &s1[sc], ec - sc + 2);
	ts[ec - sc + 1] = '\0';
	return (ts);
}
