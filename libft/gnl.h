/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:12:22 by thvocans          #+#    #+#             */
/*   Updated: 2017/08/24 23:33:14 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 2048
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

struct	s_gnl
{
	char			*str;
	int				itm;
	int				fd;
};
typedef struct s_gnl	t_gnl;

#endif
