/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 18:29:19 by thvocans          #+#    #+#             */
/*   Updated: 2017/06/15 21:21:18 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define LARG 640
# define HAUT 480

# include "mlx.h"
# include <stdio.h>
# include "./libft/libft.h"

struct s_dot
{
	char	*line;
	int		
};
typedef struct s_dot t_dot;

struct s_img
{
	void	*pt;
	int		*px;
	int		ln;
	int		bpp;
	int		end;
};
typedef struct s_img t_img;

struct s_key
{
	unsigned char	down[40];
	short			oct;
	short			bit;
	short			mask;
	unsigned int	*pt;
};
typedef struct s_key t_key;

struct s_mlx
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;

	int		fd;
	int		**map;

	t_img	img;
	t_key	key;
};
typedef struct s_mlx t_mlx;

int     is_on(t_key *key);
int     ft_key(int key, void *p);
int     press(int key, void *p);
int     release(int key, void *p);
void    ft_init_key(t_key *key);
int		parser(t_mlx *w);
# endif
