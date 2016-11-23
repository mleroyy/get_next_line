/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleroy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 16:09:15 by mleroy            #+#    #+#             */
/*   Updated: 2016/11/23 19:52:31 by mleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 10

#include "Libft/libft.h"

typedef struct	s_info
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	char	*p;
	int		line;
}				t_info;
int		get_next_line(const int fd, char **line);
#endif
