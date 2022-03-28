/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:02:52 by aaitbelh          #+#    #+#             */
/*   Updated: 2021/11/17 12:34:15 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len;
	size_t	i;
	size_t	c;
	size_t	j;

	i = 0;
	c = 0;
	len = 0;
	j = 0;
	i = ft_strlen(src);
	if (!dest && size == 0)
		return (i);
	len = ft_strlen(dest);
	c = len;
	if (c > size)
		return (i + size);
	while (src[j] && len + 1 < size)
	{
		dest[len] = src[j];
		j++;
		len++;
	}
	dest[len] = '\0';
	return (c + i);
}
