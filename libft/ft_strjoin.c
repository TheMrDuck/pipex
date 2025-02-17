/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aswedan <aswedan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:36:02 by aswedan           #+#    #+#             */
/*   Updated: 2024/09/08 14:54:17 by aswedan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		c;
	int		i;
	int		j;
	char	*sum;

	c = 0;
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	sum = (char *) malloc ((i + j + 1) * sizeof(char));
	if (!sum)
		return (NULL);
	while (s1[c])
	{
		sum[c] = s1[c];
		c++;
	}
	c = 0;
	while (s2[c])
	{
		sum[i + c] = s2[c];
		c++;
	}
	sum [i + c] = '\0';
	return (sum);
}
