/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleroy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:17:38 by mleroy            #+#    #+#             */
/*   Updated: 2016/11/14 16:39:00 by mleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*p;
	t_list	*new;

	if (lst == NULL)
		return (NULL);
	new = f(lst);
	if (new == NULL)
		return (NULL);
	new = f(lst);
	p = new;
	while (lst->next)
	{
		lst = lst->next;
		if (!(p->next = f(lst)))
			return (NULL);
		p = p->next;
	}
	return (new);
}
