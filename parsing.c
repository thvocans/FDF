/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 17:04:47 by thvocans          #+#    #+#             */
/*   Updated: 2017/09/12 19:21:31 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_htoi(char *str)
{
	int		i;
	int		out;
	char	oct;

	i = 0;
	out = 0;
	if (str[0] == ',')
		i++;
	if (str[1] == '0')
		i++;
	if (str[2] == 'x' || str[2] == 'X')
		i++;
	while (str[i])
	{
		oct = str[i];
		if (ft_isdigit(str[i]))
				oct = str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
				oct = str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
				oct = str[i] - 'A' + 10;
		else
			break ;
		out = (out << 4) + oct;
		i++;
	}
	return (out);
}

int		*get_nbr(t_map *map)
{
	int		i;
	int		j;
	char	**split;
	
	i = 0;
	j = 0;
	split = ft_strsplit(map->line, ' ');
	while (split[i]) //longueur du tableau
		i++;
	map->m_x = i;
	//malloc du nombre d'ints
	if (!(map->px = malloc(sizeof(int) * i)) ||
			!(map->pc = malloc(sizeof(int) * i)) ||
			!(map->p_x = malloc(sizeof(int) * i)) ||
			!(map->p_y = malloc(sizeof(int) * i)))
		return (NULL); //error fct
	while (j < i) //heigh to num + color to num
	{
		map->px[j] = ft_atoi(split[j]); //px_height
		if ((split[j] = ft_strchr(split[j], ','))) //px_color
			map->pc[j] = ft_htoi(split[j]);//convert hex to int
		else
			map->pc[j] = 0xFFFFFF; //default color
		j++;
	}
	return (0);
}

int		parser(t_mlx *w, char *av)
{
	int		fd;
	t_map	*map;
	char	*line;

	w->map = malloc(sizeof(*w->map)); //protect
	map = w->map;
	fd = open(av, O_RDONLY);
	w->m_y = 0;
	if (gnl(fd, &line) > 0)
	{
		map->line = line;
		get_nbr(map);
		w->m_y = 1;
	}
	while (gnl(fd, &line) > 0)
	{
		map->next = malloc(sizeof(*map)); //protect
		map = map->next;
		map->line = line;
		map->next = NULL;
		START;
		get_nbr(map);
		STOP;
		PRINTTIME;
		w->m_y++; //line qty;
	}
	close(fd);
	return (0);
}
