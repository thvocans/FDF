/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 17:28:15 by thvocans          #+#    #+#             */
/*   Updated: 2017/04/13 19:28:52 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_init(t_itoa *var)
{
	var->neg = (var->cpy < 0 ? -1 : 1);
	var->i = (var->neg < 0 ? 1 : 0);
	var->size = 1 + var->i;
	var->cpy = (var->neg > 0 ? (var->cpy) : (var->cpy * -1));
	var->tmp = var->cpy;
	while (var->tmp > 9)
	{
		var->size += 1;
		var->tmp /= 10;
	}
	var->tmp = var->cpy;
	var->out = malloc(sizeof(char) * var->size + 1);
}

char		*ft_itoa(int n)
{
	t_itoa	var;

	var.cpy = n;
	ft_init(&var);
	if (!var.out)
		return (NULL);
	if (var.neg < 0)
		var.out[0] = '-';
	var.out[var.size--] = '\0';
	while (var.size >= var.i)
	{
		var.out[var.size--] = (var.cpy % 10) + '0';
		var.cpy /= 10;
	}
	return (var.out);
}
