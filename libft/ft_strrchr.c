/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:46:20 by aaitbelh          #+#    #+#             */
/*   Updated: 2021/11/13 00:45:29 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{	
	char	*ptr;

	ptr = (char *)str;
	if (c == 0 && *str == '\0')
		return ((char *)str);
	while (*str)
		str++;
	while (str >= ptr)
	{
		if (*str == (char )c)
		{
			return ((char *)str);
		}
		str--;
	}
	return (NULL);
}
