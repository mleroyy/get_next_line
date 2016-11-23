/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleroy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 08:29:55 by mleroy            #+#    #+#             */
/*   Updated: 2016/11/10 13:05:44 by mleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char	*ft_itoa(int n)
{
	char			*string;
	int				index;
	int				sign;
	long long int	conv;

	conv = n;
	sign = (conv < 0) ? 1 : 0;
	if ((string = ft_strnew(ft_get_llintlen(conv))) == NULL)
		return (NULL);
	if (sign)
		string[0] = '-';
	conv = (conv < 0) ? -conv : conv;
	index = ft_get_llintlen(conv) - 1;
	while (index >= 0)
	{
		string[index-- + sign] = (conv % 10) + 48;
		conv /= 10;
	}
	string[ft_strlen(string)] = '\0';
	return (string);
}
