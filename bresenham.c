/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 00:36:13 by thvocans          #+#    #+#             */
/*   Updated: 2017/09/26 20:07:47 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_trace(t_mlx *w, t_map *map, int x, int *t)
{
	int		wx;
	int		u;

	wx = (w->x / 2) - 1;
	u = (w->y / 2) - 1;
	while (1)
	{//			right				left
		if (t[6] <= wx - w->mx && t[6] >= -wx - w->mx &&
			t[8] <= u + w->my && t[8] >= -u + w->my)//down  up
			w->img.px[w->mid + t[6] + (t[8] * w->x)] = map->pc[x];
		if (t[6] == t[7] && t[8] == t[9])
			return ;
		t[5] = t[4];
		if (t[5] > -t[0])
			t[4] -= t[1];
		if (t[5] > -t[0])
			t[6] += t[2];
		if (t[5] < t[1])
			t[4] += t[0];
		if (t[5] < t[1])
			t[8] += t[3];
	}
}

static void	ft_jpx_y(t_mlx *w, t_map *map, int x)
{
	int		t[10];

	t[6] = (int)map->q[x].x;
	t[7] = (int)map->next->q[x].x;
	t[8] = (int)map->q[x].y;
	t[9] = (int)map->next->q[x].y;
	t[0] = abs(t[7] - t[6]);
	t[1] = abs(t[9] - t[8]);
	t[2] = t[6] < t[7] ? 1 : -1;
	t[3] = t[8] < t[9] ? 1 : -1;
	t[4] = (t[0] > t[1] ? t[0] : -t[1]) / 2;
	ft_trace(w, map, x, t);
}

static void	ft_jpx_x(t_mlx *w, t_map *map, int x)
{
	int		t[10];

	t[6] = (int)map->q[x].x;
	t[7] = (int)map->q[x + 1].x;
	t[8] = (int)map->q[x].y;
	t[9] = (int)map->q[x + 1].y;
	t[0] = abs(t[7] - t[6]);
	t[1] = abs(t[9] - t[8]);
	t[2] = t[6] < t[7] ? 1 : -1;
	t[3] = t[8] < t[9] ? 1 : -1;
	t[4] = (t[0] > t[1] ? t[0] : -t[1]) / 2;
	ft_trace(w, map, x, t);
}

void		ft_join_px(t_mlx *w)
{
	int		t[2];
	int		x;
	t_map	*map;

	map = w->map;
	while (map)
	{
		x = 0;
		while (x + 1 < map->m_x)
		{
			t[0] = (int)map->q[x].x;
			t[1] = (int)map->q[x].y;
			ft_jpx_x(w, map, x);
			if (map->next)
			{
				if (x == 0)
					ft_jpx_y(w, map, x);
				else
					ft_jpx_y(w, map, x + 1);
			}
			x++;
		}
		map = map->next;
	}
}
