/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleroy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:59:10 by mleroy            #+#    #+#             */
/*   Updated: 2016/11/08 19:42:19 by mleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char		*p1;
	char		*p2;

	p1 = (void *)s1;
	p2 = (void *)s2;
	while (n > 0)
	{
		if (*p1 != *p2)
		{
			return ((unsigned char)*p1 - (unsigned char)*p2);
		}
		p1++;
		p2++;
		n--;
	}
	return (0);
}
