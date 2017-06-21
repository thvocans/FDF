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

	split = ft_strsplit(line, ' ');

	return (out);
}

int		parser(t_mlx *w, char *av)
{
	int		fd;
	char	*line;

	w->map = malloc(sizeof(*w->map));
	fd = open(av, O_RDONLY);
	gnl(fd, &line);
	get_nbr(w->map);

	/*	while (gnl(fd, &line) > 0)
	{
		
	}
*/}
