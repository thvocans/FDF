/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 18:07:36 by thvocans          #+#    #+#             */
/*   Updated: 2017/04/23 15:55:55 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;
	const char		*src2;

	i = 0;
	src2 = (const char *)src;
	if (dst > src)
		while (len--)
			((char *)dst)[len] = ((const char *)src)[len];
	else
		while (len--)
			((char *)dst)[i++] = *src2++;
	return (dst);
}
