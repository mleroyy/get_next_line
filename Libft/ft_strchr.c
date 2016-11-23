/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleroy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:55:15 by mleroy            #+#    #+#             */
/*   Updated: 2016/11/10 13:50:17 by mleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		len;
	char	character;

	i = 0;
	len = ft_strlen(s);
	character = c;
	while (i <= len)
	{
		if (s[i] == character)
			return ((char *)&s[i]);
		else
			i++;
	}
	return (NULL);
}
