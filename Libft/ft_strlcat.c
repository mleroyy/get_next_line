/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleroy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 12:12:24 by mleroy            #+#    #+#             */
/*   Updated: 2016/11/07 14:15:41 by mleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	int		h;
	int		j;
	int		len;
	int		delta;

	j = 0;
	i = 0;
	h = 0;
	while (dst[i])
		i++;
	while (src[h])
		h++;
	delta = size - i;
	if (delta < 0)
		len = size + h;
	else
		len = h + i;
	while (delta - 1 > 0 && src[j])
	{
		dst[i++] = src[j++];
		delta--;
	}
	dst[i] = '\0';
	return (len);
}
