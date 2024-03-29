#include "get_next_line.h"

static int		ft_sheep_dog(t_info *info, char **line, char **s)
{
	char		*p;
	char		*t;

	t = *line;
	if ((p = ft_strchr(*s, '\n')) == NULL)//s'il n'y a pas de de \n dans le tmp
	{
		*line = ft_strjoin(*line, *s);
		free(t);
		t = NULL;
		*s = NULL;//pour vider le tmp lorsque je copie le reste du tmp dans line
		return (0);
	}
	//s'il y a un \n dans la chaine de caractere
	*p++ = '\0';
	*line = ft_strjoin(*line, *s);//je rajoute dans line le debut de la chaine, penser a gerer si line est null ou pas. le strjoin ne marchera pas si line est null
	free(t);
	t = NULL;
	info->tmp = p;//je mets le reste de la chaine dans temporary
	p = NULL;//je free ??
	info->line += 1;//j'incremente le compteur de ligne lues
	return (1);//je renvoie 1 a GNL pour lui dire que ce n'est pas fini de lire
}

int				get_next_line(const int fd, char **line)
{
	static t_info	info;
	char			*b;

	if (line == NULL || fd == -1 || BUFF_SIZE <= 0)
		return (-1);
	if ((*line = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))) == NULL)
		return (-1);
	ft_bzero(*line, BUFF_SIZE);
	if ((info.tmp) != NULL)//si quand j'appelle gnl, il y a encore des caracteres dans le tmp
		if (ft_sheep_dog(&info, line, (char **)&(info.tmp)))//il remnpli line avec soit le debut de la chaine soit la chaine complete s'il ne rencontre pas de \n et retourne 1 s'il trouve un \n.
			return (1);
	while ((info.ret = read(fd, info.buf, BUFF_SIZE)) > 0)// s'il n'y a rien dans info.tmp ou que la totalite du tmp a etait mis dans line sans avoir rencontre de \n, on recommence a remplir le buffer avec read.
	{
		info.buf[info.ret] = '\0';
		b = info.buf;
		if (ft_sheep_dog(&info, line, &b))//pareil que plus haut
			return (1);
	}
	if ((info.ret == 0) && (ft_strlen(*line) != 0))
			return (1);
	return (info.ret);
}
