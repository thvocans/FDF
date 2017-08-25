/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 21:59:40 by thvocans          #+#    #+#             */
/*   Updated: 2017/08/25 04:23:26 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	printer(t_mlx *w)
{
	int		i; //current px
	int		j;
	t_map	*map;
	int		mid;
	int		step;

	mid = (w->x * w->y) / 2;		//window middle pixel
	step = 2;						//initial space step
	j = 0;
	map = w->map;					//working link
	while (map)						//line exists 
	{
		i = 0;						//init
		while (i < map->nb)			//current px < total px qty
		{		//go up entire lines 
			map->p_y[i] = (w->y / 2) - (step * (w->p_l / 2)) + (j * step);
			map->p_x[i] = (w->x / 2) - (step * (map->nb / 2)) + (i * step);
//			printf("p_y%d|p_x%d|i%d|\n", map->p_y[i], map->p_x[i], i);
			w->img.px[map->p_y[i] * w->x + map->p_x[i]] = map->pc[i];
			i++;
		}
//		printf("\nj:%d\n", j);
		j++;
		map = map->next; //next line
	}
	//while line
	//{get line
	//put line to img
	//}
	mlx_put_image_to_window(w->mlx, w->win, w->img.pt, 0,0);//refresh screen
}
