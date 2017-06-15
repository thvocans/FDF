/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 19:17:43 by thvocans          #+#    #+#             */
/*   Updated: 2017/06/14 19:43:50 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <stdio.h>
#include "libft/libft.h"

int		is_on(t_key *key)
{
	int i;

	i = 0;
	while (i < 10)
		if (key->pt[i++] != 0)
			return (1);
	return (0);
}

int		ft_key(int key, void *p)
{
	t_mlx *w;
	static int x = 0;
	static int y = 0;
	static int pc = 0xFFFFFF;

	w = (t_mlx*)p;
	if (key == 53)
		exit(0);
	if (key == 11) // b
		pc = 0x0000FF;//blue
	if (key == 15) // r
		pc = 0xFF0000;// red
	if (key == 117) // del
		pc = 0x000000; // black

	if ((w->key.down[15]) & (1 << 3) && (w->img.px[LARG * y + --x] = pc) == pc) //left 123
		mlx_put_image_to_window(w->mlx, w->win, w->img.pt, 0,0);
	if ((w->key.down[15]) & (1 << 4) && (w->img.px[LARG * y + ++x] = pc) == pc) // right 124
		mlx_put_image_to_window(w->mlx, w->win, w->img.pt, 0,0);
	if ((w->key.down[15]) & (1 << 5) && (w->img.px[LARG * ++y + x] = pc) == pc) // down
		mlx_put_image_to_window(w->mlx, w->win, w->img.pt, 0,0);
	if ((w->key.down[15]) & (1 << 6) && (w->img.px[LARG * --y + x] = pc) == pc) // up
		mlx_put_image_to_window(w->mlx, w->win, w->img.pt, 0,0);
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
	//	printf("down:%d",w->key.down[w->key.oct]);
	//	printf("m:%d oct:%d bit:%d \n",w->key.mask, w->key.oct, w->key.bit);
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

//	ft_key(key, p);
	return (0);
}

void	ft_init_key(t_key *key)
{
	unsigned char i;

	key->pt = (unsigned int*)key->down;
	i = 0;
	while (i < 10)
		key->pt[i++] = 0;
}
