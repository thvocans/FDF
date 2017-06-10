/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:13:43 by thvocans          #+#    #+#             */
/*   Updated: 2017/04/13 15:26:42 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*out;
	int		i;

	if (s && f)
	{
		i = -1;
		if (!(out = malloc(sizeof(char) * ft_strlen(s) + 1)))
			return (NULL);
		while (s[++i])
			out[i] = f(s[i]);
		out[i] = '\0';
		return (out);
	}
	return (NULL);
}
