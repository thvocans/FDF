/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 18:29:19 by thvocans          #+#    #+#             */
/*   Updated: 2017/08/25 04:23:33 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define LARG 1280
# define HAUT 960

# include "mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include "./libft/libft.h"

typedef struct s_map t_map;
struct s_map
{
	int		nb;		//nb of px, len of tab
	char	*line;	//raw line data
	int		*px;	//p_height
	int		*pc;	//p_color
	int		*p_x;	//p_xpos
	int		*p_y;	//p_ypos
	t_map	*next;
};

typedef struct s_img t_img;
struct s_img
{
	void	*pt;		//struct img pointer new img

//values returned by get_data_addr
	int		*px;		//img string casted : int = px color
						//bits : AARRGGBB white : 0xFFFFFF
	int		ln;			//line len
	int		bpp;		//bits per pixel
	int		end;		//endian
};

typedef struct s_key t_key;
struct s_key
{
	unsigned char	down[40];	//key pressed tab
	short			oct;		//which oct to check
	short			bit;		//which bit in oct
	short			mask;		//check this bit only
	unsigned int	*pt;		//pt to down tab
};

typedef struct s_mlx t_mlx;
struct s_mlx
{
	void	*mlx;		//mlx server struct pointer
	void	*win;		//1st window pointer
	int		x;			//win h len / number of px in line / LARG
	int		y;			//win v len / number of lines / HAUT

	int		fd;			//open map filedescriptor
	int		p_l;		//map line qty

	t_img	img;		//img related
	t_key	key;		//key related stuff
	t_map	*map;		//linked list with map infos
};

void	printer(t_mlx *w);
int     is_on(t_key *key);				//not used yet
int     ft_key(int key, void *p);		//key pressed to img
int     press(int key, void *p);		//toggle pressed keys
int     release(int key, void *p);		//toggle released keys
void    ft_init_key(t_key *key);		//init all to 0
int		parser(t_mlx *w, char *av);		//reading stuff starts here
# endif
