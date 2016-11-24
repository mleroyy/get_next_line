/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleroy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 16:07:58 by mleroy            #+#    #+#             */
/*   Updated: 2016/11/24 21:03:04 by mleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdio.h>

void	ft_putnbr(int nb);
void	ft_putchar(char c);


int		get_next_line(const int fd, char **line)
{
	static t_info	info;
	int				ret;
	int				i;
	int				print;

	print = 0;
	i = -1;
	if (line == NULL || fd == -1 || BUFF_SIZE <= 0)
		return (-1);
	if ((*line = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))) == NULL)
		return (-1);
	while ((ret = read(fd, info.buf, BUFF_SIZE)))
	{
		info.buf[ret] = '\0';

	}
	return (0);
}
