/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleroy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:36:37 by mleroy            #+#    #+#             */
/*   Updated: 2016/11/07 19:23:20 by mleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	res = (void *)big;
	if (little[0] == 0)
		return (res);
	while (res[i])
	{
		while (res[i + j] == little[j])
		{
			if ((res[i + j] == little[j]) && little[j + 1] == '\0')
				return (res + i);
			else
				j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
