/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 21:59:40 by thvocans          #+#    #+#             */
/*   Updated: 2017/09/22 01:11:03 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_img(t_mlx *w)
{
	int i;

	i = 0;
	while (i < (LARG * HAUT))
		w->img.px[i++] = 0;
}

/*
** Reads pixels datas stores to img, then put img to window
*/

void	store_quat(t_mlx *w, t_quat rot)
{
	int		x;
	t_map	*map;

	w->rot = quat_mult(w->rot, rot);
	map = w->map;
	while (map)
	{
		x = 0;
		while (x < map->m_x)
		{
			map->q[x] = pure_quat(map->p_x[x], map->p_y[x], map->px[x]);
			map->q[x] = quat_rot(map->q[x], w->rot);
			x++;
		}
		map = map->next; //next line
	}
	printer(w);
}
void	printer(t_mlx *w)
{
	int		x;
	t_map	*map;
	int     mid;
	int	t = w->x / 2;
	int	u = w->y / 2;
	
	clear_img(w);
	mid = (w->x * (w->y + 1)) / 2;        //window middle pixel
	map = w->map;
	while (map)
	{
		x = 0;
		while (x < map->m_x)
		{
			// write if final value is in window tolerances
			if (map->q[x].x <= t - 1 && map->q[x].x >= -t &&
				map->q[x].y <= u - 1 && map->q[x].y >= -u)
				w->img.px[mid + (int)map->q[x].x + ((int)map->q[x].y * w->x)] = map->pc[x];
			x++;
		}
		map = map->next; //next line
	}
//	if (w->step != 1)
//		ft_join_px(w);
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
	store_quat(w, rot_quat(0, 1, 0, 0));
}

void	map_init(t_mlx *w)
{
	int		i; //current px
	int		j;
	t_map	*map;

	w->step = 2;					//initial space step
	w->rot = rot_quat(0, 1, 0, 0);
	zoom(w);
	store_quat(w, quat_mult(rot_quat(-60, 1, 0, 0), rot_quat(15, 0, 0, 1)));
}
