/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 12:29:47 by thvocans          #+#    #+#             */
/*   Updated: 2017/04/12 16:51:24 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int tmp;
	int cptr;

	cptr = 1;
	if (n < 0)
		ft_putchar('-');
	if (n < 0 && n != -2147483648)
		n = n * -1;
	if (n == -2147483648)
	{
		n = 147483648;
		ft_putchar('2');
	}
	tmp = n;
	while (tmp >= 10)
	{
		cptr = cptr * 10;
		tmp /= 10;
	}
	while (cptr >= 1)
	{
		ft_putchar(((n / cptr) % 10) + 48);
		cptr /= 10;
	}
}
