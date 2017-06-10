/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 16:42:30 by thvocans          #+#    #+#             */
/*   Updated: 2017/04/19 18:18:47 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*out;

	tmp = f(lst);
	out = tmp;
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		if (!(tmp->next = f(lst)))
			return (NULL);
		tmp = tmp->next;
	}
	return (out);
}
