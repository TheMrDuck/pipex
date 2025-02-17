/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aswedan <aswedan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 09:54:16 by aswedan           #+#    #+#             */
/*   Updated: 2024/09/16 11:43:34 by aswedan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cw(char const *s, char c)
{
	int	i;

	i = 0;
	if (!*s)
		return (0);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			i++;
		while (*s && *s != c)
			s++;
	}
	return (i);
}

static void	freeing(char **ns)
{
	int	i;

	i = 0;
	while (ns[i])
	{
		free(ns[i]);
		i++;
	}
	free(ns);
}

static char	**splitting(const char *s, char **ns, char c, int j)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				j = ft_strlen(s);
			else
				j = ft_strchr(s, c) - s;
			ns[i] = ft_substr(s, 0, j);
			if (!ns[i])
			{
				freeing(ns);
				return (NULL);
			}
			i++;
			s += j;
		}
	}
	ns[i] = NULL;
	return (ns);
}

char	**ft_split(char const *s, char c)
{
	int		j;
	char	**ns;

	j = ft_cw(s, c);
	ns = malloc((j + 1) * sizeof(char *));
	if (!ns)
		return (NULL);
	ns = splitting(s, ns, c, j);
	return (ns);
}
