/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 21:59:40 by thvocans          #+#    #+#             */
/*   Updated: 2017/09/20 22:41:20 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_img(t_mlx *w)
{
	int i;

	i = 0;
	START;
	while (i < (LARG * HAUT))
	{
		w->img.px[i++] = 0;
	}
	STOP;
	PRINTTIME;
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
	int	t = w->x / 2;
	int	u = w->y / 2;
	
	clear_img(w);
	mid = (w->x * w->y) / 2 + w->x / 2;        //window middle pixel
	w->rot = quat_mult(w->rot, rot);
	map = w->map;
	while (map)
	{
		x = 0;
		while (x < map->m_x)
		{
			q = pure_quat(map->p_x[x], map->p_y[x], map->px[x]);
			q = quat_rot(q, w->rot);
			// write if final value is in window tolerances
//			if (q.x <= w->x / 2  - 1 && q.x >= w->x / 2 * -1 &&
//					q.y <= w->y / 2 - 1 && q.y >= w->y / 2 * -1)
			if (q.x <= t  - 1 && q.x >= -t &&
					q.y <= u - 1 && q.y >= -u)
				w->img.px[mid + (int)q.x + ((int)q.y * w->x)] = map->pc[x];
			x++;
		}
		map = map->next; //next line
	}
	mlx_put_image_to_window(w->mlx, w->win, w->img.pt, 0,0);//refresh screen
}

void	zoom(t_mlx *w)
{
	int		i;
	int		j;
	t_map	*map;

	j = 0;
	printf("step:%d\n",w->step);
	map = w->map;
	while (map)
	{
		i = 0;
		while (i < map->m_x)
		{
			map->p_y[i] = (j * w->step) - w->step * (w->m_y / 2);
			map->p_x[i] = (i * w->step) - w->step * (map->m_x / 2);
			i++;
		}
		j++;
		map = map->next;
	}
	printer(w, rot_quat(0, 1, 0, 0));
}

void	map_init(t_mlx *w)
{
	int		i; //current px
	int		j;
	t_map	*map;

	w->step = 2;					//initial space step
	j = 0;							//current line printing
	map = w->map;					//working link
	w->rot = rot_quat(0, 1, 0, 0);
	while (map)						//line exists 
	{
		i = 0;						//init
		while (i < map->m_x)			//current px < total px qty
		{		//go up entire lines	step * haut map / 2 + (line * step)
			map->p_y[i] = (j * w->step) - w->step * (w->m_y / 2); // coor relatives
			map->p_x[i] = (i * w->step) - w->step * (map->m_x / 2); //coor relatives
			i++;
		}
		j++;
		map = map->next; //next line
	}
	printer(w, quat_mult(rot_quat(-60, 1, 0, 0), rot_quat(15, 0, 0, 1)));
}
