/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 15:59:32 by thvocans          #+#    #+#             */
/*   Updated: 2017/09/26 19:31:10 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "error.h"

void	ft_error(int error)
{
	if (error == 0)
		ft_putstr_fd(NO_ARG, 2);
	if (error == 1)
		ft_putstr_fd(TOO_MUCH_ARG, 2);
	if (error == 2)
		perror(NO_MEM);
	exit(1);
}
