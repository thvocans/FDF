/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 20:49:08 by thvocans          #+#    #+#             */
/*   Updated: 2017/04/23 17:10:18 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_sqrt(size_t nb)
{
	size_t test;
	size_t out;

	if (nb == 1)
		return (1);
	test = 1;
	out = 0;
	while (out * out < nb)
	{
		out = test + 1;
		test++;
	}
	if (out * out == nb)
		return (out);
	else
		return (0);
}
