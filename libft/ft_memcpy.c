/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:43:12 by thvocans          #+#    #+#             */
/*   Updated: 2017/04/23 15:53:16 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst1;
	const char	*src1;

	dst1 = (char *)dst;
	src1 = (const char *)src;
	while (n--)
		*dst1++ = *src1++;
	return (dst);
}
