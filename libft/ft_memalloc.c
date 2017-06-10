/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 14:23:28 by thvocans          #+#    #+#             */
/*   Updated: 2017/04/13 13:32:23 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *out;

	if (!(out = malloc(sizeof(size_t) * size)))
		return (NULL);
	else
	{
		ft_bzero(out, size);
		return (out);
	}
}
