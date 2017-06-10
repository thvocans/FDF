/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 15:59:21 by thvocans          #+#    #+#             */
/*   Updated: 2017/04/23 16:00:30 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*s;

	s = dst;
	while (*src && len > 0)
	{
		*s++ = *src++;
		len--;
	}
	while (len > 0)
	{
		*s++ = 0;
		len--;
	}
	return (dst);
}
