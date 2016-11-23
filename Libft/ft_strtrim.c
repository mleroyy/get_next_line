/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleroy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:13:20 by mleroy            #+#    #+#             */
/*   Updated: 2016/11/10 16:14:47 by mleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			*ft_strtrim(char const *s)
{
	char	*trim;
	int		end;
	int		start;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if ((trim = (char *)malloc(sizeof(char))) == NULL)
		return (NULL);
	trim[0] = '\0';
	start = ft_get_start(s);
	end = ft_get_end(s);
	if (end <= start)
		return (trim);
	if ((trim = ft_strsub(s, start, end - start + 1)) == NULL)
		return (NULL);
	trim[ft_strlen(s)] = '\0';
	return (trim);
}
