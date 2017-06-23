/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 17:04:47 by thvocans          #+#    #+#             */
/*   Updated: 2017/06/21 17:07:33 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	map->nb = i;
	//malloc du nombre d'ints
	if (!(map->px = malloc(sizeof(int) * i)) ||
			!(map->cl = malloc(sizeof(int) * i)))
		return (NULL);
	while (j < i) //heigh to num + color to num
	{
		map->px[j] = ft_atoi(split[j]);
		if (ft_strchr(split[j], ','))
/**/		map->pc[j] = ;//put here atoi base to convert hex to int
		else
			map->pc[j] = 0xFFFFFF;
	}



/*	while (split[i])
	{
		printf("split%s\n", split[i++]);
	}
*/
	return (0);
}

int		parser(t_mlx *w, char *av)
{
	int		fd;

	w->map = malloc(sizeof(*w->map));
	fd = open(av, O_RDONLY);
	//read until line 3 to check if values are ok
	gnl(fd, &w->map->line);
	gnl(fd, &w->map->line);
	gnl(fd, &w->map->line);
	get_nbr(w->map);

	/*	while (gnl(fd, &line) > 0)
	{
		
	}
*/
	return (0);
}
