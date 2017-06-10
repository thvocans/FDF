/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:52:06 by thvocans          #+#    #+#             */
/*   Updated: 2017/04/12 17:08:40 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int tmp;
	int cptr;

	cptr = 1;
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (n < 0 && n != -2147483648)
		n = n * -1;
	if (n == -2147483648)
	{
		n = 147483648;
		ft_putchar_fd('2', fd);
	}
	tmp = n;
	while (tmp >= 10)
	{
		cptr = cptr * 10;
		tmp /= 10;
	}
	while (cptr >= 1)
	{
		ft_putchar_fd(((n / cptr) % 10) + 48, fd);
		cptr /= 10;
	}
}
