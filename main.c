/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 15:59:32 by thvocans          #+#    #+#             */
/*   Updated: 2017/06/10 19:43:22 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <stdio.h>
#include "libft/libft.h"

int		ft_key(int key, void *p)
{
	t_mlx *w;
	static int x = 0;
	static int y = 0;
	static int color = 0xFFFFFF;

	w = (t_mlx*)p;
	if (key == 53)
		exit(0);
	if (key == 11) // b
		color = 0x0000FF;//blue
	if (key == 15) // r
		color = 0xFF0000;// red
	if (key == 117) // del
		color = 0x000000; // black
	if ((w->key.down[15]) & (1 << 3)) //left 123
	{
		w->img.px[LARG * y + --x] = color;
		mlx_put_image_to_window(w->mlx, w->win, w->img.pt, 0,0);
//		printf("x:%d\n",x);
	}
	if ((w->key.down[15]) & (1 << 4)) // right 124
	{
		w->img.px[LARG * y + ++x] = color;
		mlx_put_image_to_window(w->mlx, w->win, w->img.pt, 0,0);
//		printf("x:%d\n",x);
	}
	if ((w->key.down[15]) & (1 << 5)) // down
	{
		w->img.px[LARG *(++y) + x] = color;
		mlx_put_image_to_window(w->mlx, w->win, w->img.pt, 0,0);
//		printf("y:%d\n",y);
	}
	if ((w->key.down[15]) & (1 << 6)) // up
	{
		w->img.px[LARG *(--y) + x] = color;
		mlx_put_image_to_window(w->mlx, w->win, w->img.pt, 0,0);
//		printf("y:%d\n",y);
	}
	return (0);
}

int		press(int key, void *p)
{
	t_mlx *w;

	w = (t_mlx*)p;
	w->key.oct = key / 8;
	w->key.bit = key % 8;
	w->key.mask = (char)(1 << w->key.bit);
	w->key.down[w->key.oct] = w->key.down[w->key.oct] | w->key.mask;
	printf("down:%d",w->key.down[w->key.oct]);
	printf("m:%d oct:%d bit:%d \n",w->key.mask, w->key.oct, w->key.bit);
	ft_key(key, p);
	return (0);
}

int		release(int key, void *p)
{
	t_mlx *w;

	printf("		relase: %d\n",key);
	w = (t_mlx*)p;
	w->key.oct = key / 8;
	w->key.bit = key % 8;
	w->key.mask = (char)(1 << w->key.bit);
	w->key.down[w->key.oct] = w->key.down[w->key.oct] ^ w->key.mask;

	ft_key(key, p);
	return (0);
}

void	ft_init_key(t_key *key)
{
	char i;

	key->pt = (unsigned int*)key->down;
	i = 0;
	while (i < 10)
		key->pt[i++] = 0;
}

int		main()
{
	t_mlx w;

	w.x = LARG;
	w.y = HAUT;

	ft_init_key(&w.key);
	w.mlx = mlx_init();
	w.win = mlx_new_window(w.mlx, w.x, w.y, "Teh Wintoh");
	w.img.pt = mlx_new_image(w.mlx, w.x, w.y);
	w.img.px = (int*)mlx_get_data_addr(w.img.pt, &(w.img.bpp), &(w.img.ln), &(w.img.end));
	printf("bpp:%d| line:%d| endian:%d\n",w.img.bpp, w.img.ln, w.img.end);
	mlx_hook(w.win, 2, (1L<<0), &press, &w);
	mlx_hook(w.win, 3, (1L<<1), &release, &w);
	mlx_loop(w.mlx);
}
