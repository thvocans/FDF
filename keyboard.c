/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 19:17:43 by thvocans          #+#    #+#             */
/*   Updated: 2017/09/26 20:20:15 by thvocans         ###   ########.fr       */
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

/*
**	t_mlx		*w;	
**	static int	x = 0;
**	static int	y = 0;
**	static int	pc = 0xFFFFFF;
**
**	w = (t_mlx*)p;
**	if ((w->key.down[1]) & (1 << 3)) //b
**		pc = 0x0000FF;//blue
**	if ((w->key.down[1]) & (1 << 7)) //r
**		pc = 0xFF0000;//red
**	if ((w->key.down[14]) & (1 << 5)) //del
**		pc = 0x000000; //black
** touche 1-9 = 83 - 92;
** fleches g|d|b|h : 15 1<<3 | 15 1<<4 | 15 1<<5 | 15 1<<6
*/
static void ft_key2(t_mlx *w)
{
	//translations
	if ((w->key.down[15]) & (1 << 3) && (w->mx -= 10) == w->mx) //left arrow
	{
		w->mid -= 10;
		store_quat(w, rot_quat(0, 0, 1, 0));
	}
	if ((w->key.down[15]) & (1 << 4) && (w->mx += 10) == w->mx) // right arrow
	{
		w->mid += 10;
		store_quat(w, rot_quat(0, 0, 1, 0));
	}
	if ((w->key.down[15]) & (1 << 5) && (w->my -= 10) == w->my) // down arrow
	{
		w->mid += 10 * (w->x);
		store_quat(w, rot_quat(0, 1, 0, 0));
	}
	if ((w->key.down[15]) & (1 << 6) && (w->my += 10) == w->my) // up arrow
	{
		w->mid -= 10 * (w->x);
		store_quat(w, rot_quat(0, 1, 0, 0));
	}
	if ((w->key.down[9]) & (1 << 6) && w->step == (w->step--)) // - sign 78
		zoom(w);
	if ((w->key.down[8]) & (1 << 5) && w->step == (w->step++)) // + sign 69
		zoom(w);
}

void		ft_key(t_mlx *w)
{
	if ((w->key.down[6]) & (1 << 5)) //esc
		exit(0);
	//rotations
	if ((w->key.down[10]) & (1 << 3)) //left num 1
		store_quat(w, rot_quat(5, 0, 1, 0));
	if ((w->key.down[10]) & (1 << 5)) // right num 3
		store_quat(w, rot_quat(-5, 0, 1, 0));
	if ((w->key.down[10]) & (1 << 4)) // down num 2
		store_quat(w, rot_quat(5, 1, 0, 0));
	if ((w->key.down[10]) & (1 << 7)) // up num 5
		store_quat(w, rot_quat(-5, 1, 0, 0));
	if ((w->key.down[10]) & (1 << 6)) // counter clck z num 4
		store_quat(w, rot_quat(5, 0, 0, 1));
	if ((w->key.down[11]) & (1 << 0)) // z clock num 6
		store_quat(w, rot_quat(-5, 0, 0, 1));
	ft_key2(w);
}

int		press(int key, void *p)
{
	t_mlx *w;

	w = (t_mlx*)p;
	w->key.oct = key / 8;
	w->key.bit = key % 8;
	w->key.mask = (char)(1 << w->key.bit);
	w->key.down[w->key.oct] = w->key.down[w->key.oct] | w->key.mask;
	//printf("down:%d\n",w->key.down[w->key.oct]);
	//printf("m:%d oct:%d bit:%d \n",w->key.mask, w->key.oct, w->key.bit);
	ft_key(w);
	return (0);
}

int		release(int key, void *p)
{
	t_mlx *w;

	//printf("		relase: %d\n",key);
	w = (t_mlx*)p;
	w->key.oct = key / 8;
	w->key.bit = key % 8;
	w->key.mask = (char)(1 << w->key.bit);
	w->key.down[w->key.oct] = w->key.down[w->key.oct] ^ w->key.mask;
	ft_key(w);
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
