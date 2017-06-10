/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 18:00:52 by thvocans          #+#    #+#             */
/*   Updated: 2017/04/13 14:55:46 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*out;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	while ((s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t'))
		len--;
	if ((len = len - i) < 0)
		len = 0;
	if (!(out = malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (j < len)
		out[j++] = s[i++];
	out[j] = '\0';
	while (out[ft_strlen(out) - 1] == ' ' ||
			out[ft_strlen(out) - 1] == '\n' || out[ft_strlen(out) - 1] == '\t')
		out[ft_strlen(out) - 1] = '\0';
	return (out);
}
