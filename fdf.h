/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 18:29:19 by thvocans          #+#    #+#             */
/*   Updated: 2017/09/20 22:41:43 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define LARG 1280
# define HAUT 860

# include "mlx.h"
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "./libft/libft.h"

#include <time.h>
clock_t startm, stopm;
#define START if ( (startm = clock()) == -1) {printf("Error calling clock");exit(1);}
#define STOP if ( (stopm = clock()) == -1) {printf("Error calling clock");exit(1);}
#define PRINTTIME printf( "%.9g\n", ((double)stopm-startm)/CLOCKS_PER_SEC);

typedef struct s_map t_map;
struct s_map
{
	int		m_x;		//nb of px, len of tab
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
	int		**xy;
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

typedef struct s_quat t_quat;
struct s_quat
{
	double	w;
	double	x;
	double	y;
	double	z;
};

typedef struct s_mlx t_mlx;
struct s_mlx
{
	void	*mlx;		//mlx server struct pointer
	void	*win;		//1st window pointer
	int		x;			//win h len / number of px in line / LARG
	int		y;			//win v len / number of lines / HAUT

	int		fd;			//open map filedescriptor
	int		m_y;		//map line qty

	t_quat	rot;		//rotation quaternion	
	int		step;		//zoom step

	t_img	img;		//img related
	t_key	key;		//key related stuff
	t_map	*map;		//linked list with map infos
};

void	map_init(t_mlx *w);
int     is_on(t_key *key);				//not used yet
int     ft_key(int key, void *p);		//key pressed to img
int     press(int key, void *p);		//toggle pressed keys
int     release(int key, void *p);		//toggle released keys
void    ft_init_key(t_key *key);		//init all to 0
int		parser(t_mlx *w, char *av);		//reading stuff starts here
void	printer(t_mlx *w, t_quat rot);
void	zoom(t_mlx *w);
t_quat	quat_rot(t_quat q, t_quat rot);	//
t_quat	pure_quat(int px_x, int px_y, int px_z); //3 Dim vector to quat
t_quat	rot_quat(double angle, int axe_x, int axe_y, int axe_z); //create rot q
t_quat	quat_mult(t_quat q1, t_quat q2);

# endif
