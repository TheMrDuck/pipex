/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aswedan <aswedan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:41:34 by aswedan           #+#    #+#             */
/*   Updated: 2024/09/15 12:11:56 by aswedan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ns;
	int		c;

	c = 0;
	ns = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!ns)
		return (NULL);
	while (s[c])
	{
		ns[c] = f(c, s[c]);
		c++;
	}
	ns[c] = '\0';
	return (ns);
}
