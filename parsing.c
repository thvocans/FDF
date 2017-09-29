/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 17:04:47 by thvocans          #+#    #+#             */
/*   Updated: 2017/09/26 19:48:22 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_htoi(char *str)
{
	int		i;
	int		out;
	char	oct;

	if ((i = 0) == 0 && str[0] == ',')
		i++;
	if ((out = 0) == 0 && str[1] == '0')
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

static void	ft_get_nbr(t_map *map)
{
	int		j;
	char	**split;
	char	*color;

	map->m_x = 0;
	j = 0;
	split = ft_strsplit(map->line, ' ');
	while (split[map->m_x]) //longueur du tableau
		map->m_x++;
	if (!(map->px = malloc(sizeof(int) * map->m_x)) ||
			!(map->pc = malloc(sizeof(int) * map->m_x)) ||
			!(map->p_x = malloc(sizeof(int) * map->m_x)) ||
			!(map->p_y = malloc(sizeof(int) * map->m_x)) ||
			!(map->q = malloc(sizeof(t_quat) * map->m_x)))
		return ; //error fct
	while (j < map->m_x) //heigh to num + color to num
	{
		map->px[j] = ft_atoi(split[j]); //px_height
		if ((color = ft_strchr(split[j], ','))) //px_color
			map->pc[j] = ft_htoi(color);//convert hex to int
		else
			map->pc[j] = 0xFFFFFF; //default color
		free(split[j]);
		j++;
	}
	free(split);
}

int		ft_parser(t_mlx *w, char *av)
{
	int		fd;
	t_map	*map;
	char	*line;

	if (!(w->map = malloc(sizeof(*w->map))))
		ft_error(1);
	map = w->map;
	if ((fd = open(av, O_RDONLY)) < 0)
		ft_error(2);
	w->m_y = 0;
	if (gnl(fd, &line) > 0)
	{
		map->line = line;
		ft_get_nbr(map);
		w->m_y = 1;
	}
	while (gnl(fd, &line) > 0)
	{
		map->next = malloc(sizeof(*map)); //protect
		map = map->next;
		map->line = line;
		map->next = NULL;
		ft_get_nbr(map);
		w->m_y++; //line qty;
	}
	close(fd);
	gnl(fd, NULL);
	return (0);
}
