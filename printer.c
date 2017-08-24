/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 21:59:40 by thvocans          #+#    #+#             */
/*   Updated: 2017/08/24 03:50:46 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	printer(t_mlx *w)
{
	int		i; //current px
	t_map	*map;

	map = w->map; //working link
	while (map) //line exists 
	{
		i = 0; //init
		while (i < map->nb) //current px < total px qty
		{
		printf("2\n");
			printf("%d\n",map->px[i++]);
		}
		map = map->next; //next line
	}
	//while line
	//{get line
	//put line to img
	//}
	mlx_put_image_to_window(w->mlx, w->win, w->img.pt, 0,0);//refresh screen
}
