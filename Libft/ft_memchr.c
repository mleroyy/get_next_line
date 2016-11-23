/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleroy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:37:04 by mleroy            #+#    #+#             */
/*   Updated: 2016/11/08 16:05:01 by mleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	conv;

	conv = c;
	ptr = (void *)s;
	while (n > 0)
	{
		if (*ptr == conv)
			return ((void *)ptr);
		ptr++;
		n--;
	}
	return (NULL);
}
