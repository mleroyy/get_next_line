/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleroy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:25:34 by mleroy            #+#    #+#             */
/*   Updated: 2016/11/10 14:45:27 by mleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_nb_word(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i] && c)
	{
		while (s[i] == c)
			i++;
		if ((s[i] != c) && (s[i] != 0))
			count++;
		while ((s[i] != c) && (s[i] != 0))
			i++;
	}
	return (count);
}

static void		ft_nb_character(char const *s, char ***table, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	j = 0;
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		while ((s[i] != '\0') && (s[i] != c))
		{
			i++;
			j++;
		}
		if (j > 0)
		{
			(*table)[k] = (char *)malloc(sizeof(char) * (j + 1));
			k++;
		}
		j = 0;
		i++;
	}
}

static	void	ft_insert_character(char const *s, char ***table,
									int count, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	j = 0;
	while (s[i] == c)
		i++;
	while ((s[i] != '\0') && (k < count))
	{
		while ((s[i] != 0) && (s[i] != c))
		{
			(*table)[k][j] = s[i];
			i++;
			j++;
		}
		if (j > 0)
			(*table)[k++][j] = '\0';
		j = 0;
		i++;
	}
	(*table)[k] = 0;
}

char			**ft_strsplit(char const *s, char c)
{
	unsigned int	nb_word;
	char			**table;

	if (!s)
		return (NULL);
	nb_word = ft_nb_word(s, c);
	table = (char **)malloc(sizeof(char *) * (nb_word + 1));
	if (!table)
		return (NULL);
	ft_nb_character(s, &table, c);
	ft_insert_character(s, &table, nb_word, c);
	return (table);
}
