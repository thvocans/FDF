/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 00:36:13 by thvocans          #+#    #+#             */
/*   Updated: 2017/09/22 01:11:05 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_join_px(t_mlx *w)
{
	int	dx = abs(x1-x0);
	int	sx = x0<x1 ? 1 : -1;
	int	dy = abs(y1-y0);
	int	sy = y0<y1 ? 1 : -1; 
	int	err = (dx>dy ? dx : -dy)/2;
	int	e2;

	int x;
	int t = w->x / 2;
	int u = w->y / 2;

	t_map *map;
	map = w->map;
	while (map->next)
	{
		while (x < map->m_x)
		{
			if (q.x <= t  - 1 && q.x >= -t && q.y <= u - 1 && q.y >= -u)
			{
				dx = abs(x1-x0);

				while (1)
				{
	w->img.px[mid + (int)map->q[x].x + ((int)map->q[x].y * w->x)] = map->pc[x];
					if ((int)map->q[x].x == (int)map->q[x + 1].x &&
						(int)map->q[x].y == (int)map->q[x + 1].y)
						break;
					e2 = err;
					if (e2 > -dx)
					{
						err -= dy;
						x0 += sx;
					}
					if (e2 < dy)
					{
						err += dx;
						y0 += sy;
					}
				}

			}
		}
		map = map->next;
	}
}
