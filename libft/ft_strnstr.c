/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:40:40 by aaitbelh          #+#    #+#             */
/*   Updated: 2021/11/17 16:19:12 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	if (!str && !n)
		return (NULL);
	if (!*to_find)
		return ((char *) str);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (to_find[j] == str[i + j] && str[i + j] && i + j < n)
		{
			j++;
			if (to_find[j] == '\0')
				return ((char *) str + i);
		}
		i++;
	}
	return (0);
}
