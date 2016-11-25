/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleroy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 16:09:15 by mleroy            #+#    #+#             */
/*   Updated: 2016/11/25 19:48:58 by mathieuleroy        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 9999

#include "includes/libft.h"

typedef struct		s_info
{
	char			buf[BUFF_SIZE + 1];
	char			*tmp;//buffer temporaire pour le prochain appel de GNL
	char			*p;// pointeur sur le reste du buffer
	int				line;//nombre de lignes lues
	int				ret;//lecture finie ?
	t_list			*block;//pour stoquer les differents tmp en fonction de leur fd
}					t_info;

int		get_next_line(const int fd, char **line);

#endif
