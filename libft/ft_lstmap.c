/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aswedan <aswedan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:01:51 by aswedan           #+#    #+#             */
/*   Updated: 2024/09/16 14:20:10 by aswedan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*allocmem(void *content, void *(f)(void *), void(*del)(void *))
{
	t_list	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new -> content = (*f)(content);
	if (!new -> content)
	{
		(del)(new -> content);
		free(new);
		return (NULL);
	}
	new -> next = NULL;
	return (new);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*new;

	if (!lst || !f || !del)
		return (NULL);
	first = NULL;
	while (lst)
	{
		new = allocmem(lst -> content, f, del);
		if (!(new))
		{
			while (first)
			{
				new = first->next;
				(*del)(first->content);
				free(first);
				first = new;
			}
			return (NULL);
		}
		ft_lstadd_back(&first, new);
		lst = lst ->next;
	}
	return (first);
}
