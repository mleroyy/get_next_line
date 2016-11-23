/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleroy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:15:23 by mleroy            #+#    #+#             */
/*   Updated: 2016/11/08 22:38:26 by mleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	character;
	int		i;

	str = (void *)s;
	i = 0;
	if (c == 0)
		return (&str[ft_strlen(str)]);
	if (s != NULL)
	{
		character = c;
		while (s[i])
			i++;
		i--;
		while (i >= 0)
		{
			if (s[i] == character)
				return ((char *)s + i);
			else
				i--;
		}
		return (NULL);
	}
	else
		return (NULL);
}
