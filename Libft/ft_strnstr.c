/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleroy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:00:18 by mleroy            #+#    #+#             */
/*   Updated: 2016/11/09 16:47:09 by mleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*s1;
	int		i;
	int		j;
	int		size;

	i = -1;
	j = 0;
	size = ft_strlen(little);
	s1 = (char *)big;
	if (size == 0)
		return (s1);
	while (little[++i])
		while (len-- && s1[j])
		{
			if (little[i] == s1[j])
			{
				size--;
				if (size == 0)
					return (s1 + j - i);
				i++;
			}
			j++;
		}
	return (NULL);
}
