/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 21:59:40 by thvocans          #+#    #+#             */
/*   Updated: 2017/09/10 16:20:41 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_img(t_mlx *w)
{
	int i;

	i = 0;
	while (i < (LARG * HAUT))
	{
		w->img.px[i++] = 0x000000;
	}
}

/*
** Reads pixels datas stores to img, then put img to window
*/
void	printer(t_mlx *w, t_quat rot)
{
	int		x;
	t_map	*map;
	t_quat	q;
	int     mid;
	
	clear_img(w);
	mid = (w->x * w->y) / 2 + w->x / 2;        //window middle pixel
	map = w->map;
	while (map)
	{
		x = 0;
		while (x < map->m_x)
		{
			q = pure_quat(map->p_x[x], map->p_y[x], map->px[x]);
			q = quat_rot(q, rot);
//			printf("q	w:%f x:%f y:%f z:%f\n",q.w, q.x, q.y, q.z);
			map->p_x[x] = q.x;
			map->p_y[x] = q.y;
			map->px[x] = q.z;
			// write if final value is in window tolerances
			if (q.x <= w->x / 2  - 1 && q.x >= w->x / 2 * -1 &&
					q.y <= w->y / 2 - 1 && q.y >= w->y / 2 * -1)
				w->img.px[mid + (int)q.x + ((int)q.y * w->x)] = map->pc[x];
			x++;
		}
		map = map->next; //next line
	}
	mlx_put_image_to_window(w->mlx, w->win, w->img.pt, 0,0);//refresh screen
}

void	map_init(t_mlx *w)
{
	int		i; //current px
	int		j;
	t_map	*map;
	int		step;

	step = 10;						//initial space step
	j = 0;							//current line printing
	map = w->map;					//working link
	while (map)						//line exists 
	{
		i = 0;						//init
		while (i < map->m_x)			//current px < total px qty
		{		//go up entire lines	step * haut map / 2 + (line * step)
//	map->p_y[i] = (w->y / 2) - (step * (w->m_y / 2)) + (j * step);
			map->p_y[i] = (j * step) - step * (w->m_y / 2); // coor relatives
//	map->p_x[i] = (w->x / 2) - (step * (map->m_x / 2)) + (i * step);
			map->p_x[i] = (i * step) - step * (map->m_x / 2); //coor relatives
//	printf("p_y%d|p_x%d|i%d|\n", map->p_y[i], map->p_x[i], i);
			i++;
		}
//		printf("j:%d\n", j);
		j++;
		map = map->next; //next line
	}
	printer(w, quat_mult(rot_quat(-60, 1, 0, 0), rot_quat(15, 0, 0, 1)));
}
