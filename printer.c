/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 21:59:40 by thvocans          #+#    #+#             */
/*   Updated: 2017/09/04 22:45:41 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Reads pixels datas stores to img, then put img to window
*/
void	printer(t_mlx *w)
{
	int		x;
	int		y;
	t_map	*map;

	y = 0;
	map = w->map;
	while (map)
	{
		x = 0;
		while (x < map->nb)
		{
			// write if final value is in window tolerances
			if (map->p_x[x] <= w->x && map->p_x[x] >= 0 &&
					map->p_y[x]<= w->y && map->p_y[x] >= 0)
				w->img.px[map->p_y[x] * w->x + map->p_x[x]] = map->pc[x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(w->mlx, w->win, w->img.pt, 0,0);//refresh screen
}


void	map_init(t_mlx *w)
{
	int		i; //current px
	int		j;
	t_map	*map;
	int		mid;
	int		step;

	mid = (w->x * w->y) / 2;		//window middle pixel
	step = 2;						//initial space step
	j = 0;							//current line printing
	map = w->map;					//working link
	while (map)						//line exists 
	{
		i = 0;						//init
		while (i < map->nb)			//current px < total px qty
		{		//go up entire lines	step * haut map / 2 + (line * step)
			map->p_y[i] = (w->y / 2) - (step * (w->p_l / 2)) + (j * step);
						//
			map->p_x[i] = (w->x / 2) - (step * (map->nb / 2)) + (i * step);
//			printf("p_y%d|p_x%d|i%d|\n", map->p_y[i], map->p_x[i], i);
			i++;
		}
//		printf("j:%d\n", j);
		j++;
		map = map->next; //next line
	}
	printer(w);
}
