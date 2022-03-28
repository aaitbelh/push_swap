/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:41:33 by aaitbelh          #+#    #+#             */
/*   Updated: 2021/11/14 15:41:37 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*sr;
	unsigned char		*ds;

	if (!src && !dest)
		return (NULL);
	i = 0;
	sr = (unsigned char *)src;
	ds = (unsigned char *)dest;
	while (n--)
	{
		ds[i] = sr[i];
		i++;
	}
	return (ds);
}
