/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleroy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:47:11 by mleroy            #+#    #+#             */
/*   Updated: 2016/11/05 11:53:41 by mleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*d;
	unsigned char	*s;
	unsigned char	conv;

	conv = c;
	d = dst;
	s = (void *)src;
	while (n > 0)
	{
		*d = *s;
		d++;
		if (*s == conv)
			return (d);
		s++;
		n--;
	}
	return (NULL);
}
