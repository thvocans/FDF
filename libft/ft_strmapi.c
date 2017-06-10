/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:28:23 by thvocans          #+#    #+#             */
/*   Updated: 2017/04/13 15:38:35 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*out;
	int		i;

	if (s && f)
	{
		i = -1;
		if (!(out = malloc(sizeof(char) * ft_strlen(s) + 1)))
			return (NULL);
		while (s[++i])
			out[i] = f(i, s[i]);
		out[i] = '\0';
		return (out);
	}
	return (NULL);
}
