/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 08:54:34 by aaitbelh          #+#    #+#             */
/*   Updated: 2021/11/15 18:19:44 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*ds;
	char	*sr;

	if (!dest && !src)
		return (NULL);
	sr = (char *)src;
	ds = (char *)dest;
	i = 0;
	if (dest < src)
	{
		while (n--)
		{
			ds[i] = sr[i];
			i++;
		}
	}
	else
	{
		while (n--)
		{
			ds[i + n] = sr[i + n];
		}
	}
	return (ds);
}
