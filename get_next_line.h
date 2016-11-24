/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleroy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 16:09:15 by mleroy            #+#    #+#             */
/*   Updated: 2016/11/24 18:40:02 by mleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 34

#include "Libft/libft.h"

typedef struct	s_info
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp;//buffer temporaire pour le prochain appel de GNL
	char	*tmp2;
	char	*p;// pointeur sur le reste du buffer
	int		line;//nombre de lignes lues
}				t_info;
int		get_next_line(const int fd, char **line);
#endif
