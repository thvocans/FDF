/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 21:59:40 by thvocans          #+#    #+#             */
/*   Updated: 2017/08/23 01:36:47 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	printer(t_mlx *w)
{
	int		i; //current px
	t_map	*map;

	map = w->map; //working link
	while (map) //line exists 
	{
		i = 0; //init
		while (i < w->map.nb) //current px < total px qty
		{
			
		}
		map = map->next; //next line
	}
	//while line
	//{get line
	//put line to img
	//}
	mlx_put_image_to_window(w->mlx, w->win, w->img.pt, 0,0);//refresh screen
}
