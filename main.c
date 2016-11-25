/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleroy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 16:07:58 by mleroy            #+#    #+#             */
/*   Updated: 2016/11/25 20:02:27 by mathieuleroy        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdio.h>

void	ft_putnbr(int nb);
void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	i = 1;
	if (argc < 2)
	{
		ft_putstr("Usage: 1 file minimum is required.\n");
		return (1);
	}
	fd = open(argv[i], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Open failed.\n");
		return (1);
	}
	while((get_next_line(fd, &line) != 0))
	{
		ft_putstr(line);
		ft_putchar(10);
	}
	//get_next_line(fd, &line);
		//ft_putchar(10);
	if (close(fd) == -1)
		ft_putstr("Close failed.\n");
	return (0);
}
