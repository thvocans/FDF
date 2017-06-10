/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 14:40:35 by thvocans          #+#    #+#             */
/*   Updated: 2017/04/13 14:58:02 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *out;

	if (!(out = malloc(sizeof(char) * size + 1)))
		return (NULL);
	else
	{
		ft_bzero(out, size + 1);
		return (out);
	}
}
