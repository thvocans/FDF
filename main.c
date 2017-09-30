/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 15:59:32 by thvocans          #+#    #+#             */
/*   Updated: 2017/09/26 19:31:10 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_mlx w;

	if (ac != 2)
	{
		if (ac > 2)
			ft_error(1);
		ft_error(0);
	}		
	w.x = LARG;
	w.y = HAUT;
	ft_init_key(&w.key);
	w.mlx = mlx_init();
	w.win = mlx_new_window(w.mlx, w.x, w.y, "Teh Wintoh");
	w.img.pt = mlx_new_image(w.mlx, w.x, w.y);
	w.img.px = (int*)mlx_get_data_addr(w.img.pt, &(w.img.bpp), &(w.img.ln),\
			&(w.img.end));
//	START;
	ft_parser(&w, av[1]);
//	STOP;
//	PRINTTIME;
//	printf("bpp:%d| line:%d| endian:%d\n",w.img.bpp, w.img.ln, w.img.end);
	map_init(&w);
	mlx_hook(w.win, 2, (1L << 0), &press, &w);
	mlx_hook(w.win, 3, (1L << 1), &release, &w);
//	mlx_loop_hook(w.mlx, &latent, &w);
	mlx_loop(w.mlx);
}
