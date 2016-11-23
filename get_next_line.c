/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleroy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 16:07:58 by mleroy            #+#    #+#             */
/*   Updated: 2016/11/23 20:53:30 by mleroy           ###   ########.fr       */
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
	char			*print;
	int				ret;
	int				i;
	char			text[] = "BOOM BOOM !!!";
	int				k;

	k = 0;
	i = -1;
	if (line == NULL || fd == -1 || BUFF_SIZE <= 0)
		return (-1);
	if ((*line = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))) == NULL)
		return (-1);
	//ft_bzero(line, BUFF_SIZE);
	info.tmp = text;
	while (k < 1 && (ret = read(fd, info.buf, BUFF_SIZE)))
	{
		printf("je rentre dans la boucle / ");
		info.buf[ret] = '\0';
		if ((info.p = ft_strchr(info.buf, '\n')) != NULL)//si je trouve un \n dans le buffer
		{
			printf("YES / ");
			(*info.p) = '\0';// j'ecrase le \n en \0
			(info.p)++;//je fais pointer info.p sur tout ce au'il y a apres le \0'
			//-je mets tout ce qu'il y a avant le \n dans LINE grace a ft_strjoin
			//-je mets tout ce qu'il y a apres le \n dans INFO.BUF, le buffer statique.
		}
		else//si je ne trouve pas de \n dans le buffer
		{
			printf("NO / ");
			*line = ft_strjoin(*line, info.tmp);
		}
		k++;
	}
	ft_putstr(*line);
	info.line += 1;
	printf("\ninfo.line = %i\n", info.line);
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	*line;

	fd = open("exemple.txt", O_RDONLY);
	if (fd == -1)
		ft_putstr("Open failed.\n");
	while (get_next_line(fd, &line) != 0)
		//ft_putchar(10);
	if (close(fd) == -1)
		ft_putstr("Close failed.\n");
	return (0);
}
