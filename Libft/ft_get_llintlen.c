/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_llintlen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleroy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 10:42:50 by mleroy            #+#    #+#             */
/*   Updated: 2016/11/10 12:31:46 by mleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_get_llintlen(long long int n)
{
	int		len;
	int		neg;

	neg = 0;
	len = 0;
	if (n < 0)
	{
		n = -n;
		neg = 1;
	}
	while (n >= 10)
	{
		len++;
		n /= 10;
	}
	if (neg)
		len++;
	len++;
	return (len);
}
