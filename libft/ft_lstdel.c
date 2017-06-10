/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 16:06:08 by thvocans          #+#    #+#             */
/*   Updated: 2017/04/19 16:24:09 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *next;

	while ((*alst)->next)
	{
		next = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = next;
	}
	ft_lstdelone(alst, del);
	free(*alst);
	*alst = NULL;
}
