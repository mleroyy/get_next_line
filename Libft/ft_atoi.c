/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleroy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:39:28 by mleroy            #+#    #+#             */
/*   Updated: 2016/11/09 16:48:17 by mleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		integer;

	i = 0;
	sign = 0;
	while (!(integer = 0) && (str[i] <= 32))
	{
		if (str[i] == '\200')
			return (0);
		i++;
	}
	if (str[i] == '-')
		sign = 1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while ((str[i] >= 48) && (str[i] <= 57))
	{
		integer *= 10;
		integer += str[i] - 48;
		i++;
	}
	if (sign == 1)
		integer = -integer;
	return (integer);
}
