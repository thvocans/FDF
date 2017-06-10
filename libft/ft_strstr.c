/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 16:13:01 by thvocans          #+#    #+#             */
/*   Updated: 2017/04/23 16:15:02 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (!*s2)
		return ((char *)s1);
	while (s1[i])
	{
		j = 0;
		k = i;
		while (s1[k] == s2[j])
		{
			j++;
			k++;
			if (!s2[j])
				return (&((char *)s1)[i]);
		}
		i++;
	}
	return (NULL);
}
