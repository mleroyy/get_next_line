/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleroy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 16:07:58 by mleroy            #+#    #+#             */
/*   Updated: 2016/11/24 23:41:18 by mathieuleroy        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdio.h>

void	ft_putnbr(int nb);
void	ft_putchar(char c);

int		ft_sheep_dog(t_info *info, char **line, char *s)
{
	char	*p;
	if ((p = ft_strchr(s, '\n')) == NULL)//s'il n'y a pas de de \n dans le tmp
	{
		//je mets toute la chaine s dans line
		return (0);
	}
	else//s'il y a un \n dans la chaine de caractere
	{
		//je rajoute dans line le debut de la chaine, penser a gerer si line est null ou pas. le strjoin ne marchera pas si line est null
		//je mets le reste de la chaine dans temporary
		//je renvoie 1 a GNL pour lui dire que ce n'est pas fini de lire
		//je free ??
		//j'incremente le compteur de ligne lues
		(*p)++ = '\0';
		info.tmp = p;
	}
}

int		get_next_line(const int fd, char **line)
{
	static t_info	info;
	int				ret;

	if (line == NULL || fd == -1 || BUFF_SIZE <= 0)
		return (-1);
	if ((*line = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))) == NULL)
		return (-1);
	if (info.tmp != NULL)//si quand j'appelle gnl, il y a encore des caracteres dans le tmp
		if (ft_sheep_dog(&info, line, info.tmp))//il remnpli line avec soit le debut de la chaine soit la chaine complete s'il ne rencontre pas de \n et retourne 1 s'il trouve un \n.
			return (1);
	while ((ret = read(fd, info.buf, BUFF_SIZE)) > 0)// s'il n'y a rien dans info.tmp ou que la totalite du tmp a etait mis dans line sans avoir rencontre de \n, on recommence a remplir le buffer avec read.
	{
		info.buf[ret] = '\0';
		if (ft_sheep_dog(&info, line, info.buf))//pareil que plus haut
			return (1);
	}
	return (ret);
}
