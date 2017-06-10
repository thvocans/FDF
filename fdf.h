/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 18:29:19 by thvocans          #+#    #+#             */
/*   Updated: 2017/06/10 19:43:23 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define LARG 640
# define HAUT 480

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
	char			down[40];
	char			oct;
	char			bit;
	char			mask;
	unsigned int	*pt;
};
typedef struct s_key t_key;

struct s_mlx
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;

	t_img	img;
	t_key	key;
};
typedef struct s_mlx t_mlx;

# endif
