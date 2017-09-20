/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:12:14 by thvocans          #+#    #+#             */
/*   Updated: 2017/09/20 21:36:37 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl	*ft_create(int fd)
{
	t_gnl	*out;

	if ((out = (t_gnl*)malloc(sizeof(t_gnl))))
	{
		out->itm = 0;
		out->fd = fd;
		out->read = -2;
		out->next = NULL;
		if ((out->str = malloc(1)))
			out->str[0] = 0;
	}
	return (out);
}

static int		ft_read(int fd, t_gnl *pt)
{
	int		i;
	ssize_t	bsiz;
	char	buf[BUFF_SIZE];
	int		brk;

	while ((bsiz = read(fd, &buf, BUFF_SIZE)) > 0)
	{
		i = 0;
		brk = 0;
		pt->str = ft_malloncat(pt->str, buf, (size_t)bsiz);
		while (pt->str[pt->itm + i] && brk == 0)
		{
			if (pt->str[pt->itm + i++] == '\n')
				brk = 1;
		}
		if (brk == 1)
			break ;
	}
	pt->read = bsiz;
	return (bsiz);
}

static int		ft_store(t_gnl *pt, char **line)
{
	size_t			i;

	i = 0;
	while (!(pt->str[pt->itm + i] == '\n' || pt->str[pt->itm + i] == '\0'))
		i++;
	if (!(*line = ft_strsub(pt->str, pt->itm, i)))
		return (-1);
	if (i == 0 && pt->str[pt->itm] == '\0')
		return (0);
	pt->itm += (pt->str[pt->itm + i] != '\0') ? i + 1 : i;
	return (1);
}

static int		ft_free(int fd, t_gnl *pt, char **line)
{
	if (line == NULL && fd > 0)
	{
		while (pt != NULL && pt->fd != fd)
			pt = pt->next;
		if (pt != NULL)
			free(pt->str);
	}
	return (-1);
}

int				gnl(const int fd, char **line)
{
	static t_gnl	*var;
	t_gnl			*pt;

	pt = var;
	if (line == NULL || fd < 0)
		return (ft_free(fd, pt, line));
	if (pt != NULL)
	{
		while (pt != NULL && pt->fd != fd)
			pt = pt->next;
		if (!pt && (pt = var) == var)
		{
			while (pt->next)
				pt = pt->next;
			pt->next = ft_create(fd);
			pt = pt->next;
		}
	}
	else if ((var = ft_create(fd)))
		pt = var;
	if (!pt || ft_read(fd, pt) < 0)
		return (-1);
	return (ft_store(pt, line));
}
