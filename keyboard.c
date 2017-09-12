/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 19:17:43 by thvocans          #+#    #+#             */
/*   Updated: 2017/09/12 16:51:45 by thvocans         ###   ########.fr       */
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
	if ((w->key.down[6]) & (1 << 5)) //esc
		exit(0);
	if ((w->key.down[1]) & (1 << 3)) //b
		pc = 0x0000FF;//blue
	if ((w->key.down[1]) & (1 << 7)) //r
		pc = 0xFF0000;//red
	if ((w->key.down[14]) & (1 << 5)) //del
		pc = 0x000000; //black
	if ((w->key.down[15]) & (1 << 3)) //left 123
		printer(w, rot_quat(5, 0, 1, 0));
	if ((w->key.down[15]) & (1 << 4)) // right 124
		printer(w, rot_quat(-5, 0, 1, 0));
	if ((w->key.down[15]) & (1 << 5)) // down
		printer(w, rot_quat(5, 1, 0, 0));
	if ((w->key.down[15]) & (1 << 6)) // up
		printer(w, rot_quat(-5, 1, 0, 0));
	if ((w->key.down[9]) & (1 << 6) && w->step == (w->step--)) // - sign 78
		zoom(w);
	if ((w->key.down[8]) & (1 << 5) && w->step == (w->step++)) // + sign 69
		zoom(w);
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
	//	printf("down:%d\n",w->key.down[w->key.oct]);
	//	printf("m:%d oct:%d bit:%d \n",w->key.mask, w->key.oct, w->key.bit);
	ft_key(key, p);
	return (0);
}

int		release(int key, void *p)
{
	t_mlx *w;

//	printf("		relase: %d\n",key);
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
	unsigned char i;

	key->pt = (unsigned int*)key->down;
	i = 0;
	while (i < 10)
		key->pt[i++] = 0;
}
