/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 15:03:32 by thvocans          #+#    #+#             */
/*   Updated: 2017/04/23 16:08:07 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 && *s2 && *s1 == *s2 && n)
	{
		s1++;
		s2++;
		n--;
	}
	if (!n)
		return (*(const unsigned char *)--s1 - *(const unsigned char *)--s2);
	return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
}
