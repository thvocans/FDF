/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:52:35 by thvocans          #+#    #+#             */
/*   Updated: 2017/04/13 16:06:08 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	i;

	i = 0;
	if (s)
	{
		if (!(out = malloc(sizeof(char) * len + 1)))
			return (NULL);
		while (i < len)
			out[i++] = s[start++];
		out[i] = '\0';
		return (out);
	}
	return (NULL);
}
