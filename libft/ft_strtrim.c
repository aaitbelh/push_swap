/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:35:05 by aaitbelh          #+#    #+#             */
/*   Updated: 2021/11/15 20:25:12 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_back(const char *s1, const char *s2)
{
	int	i;
	int	len;
	int	def;
	int	h;

	def = 0;
	len = ft_strlen(s1) - 1;
	while (*(s1 + len) && len > 0)
	{
		h = 0;
		i = 0;
		while (s2[i])
		{
			if (*(s1 + len) == s2[i])
				h = 1;
			i++;
		}
		if (h == 1)
			def++;
		else
			break ;
		len--;
	}
	return (def);
}

static int	len_front(const char *s1, const char *s2)
{
	int	i;
	int	def;
	int	h;

	def = 0;
	while (*s1)
	{
		h = 0;
		i = 0;
		while (s2[i])
		{
			if (*s1 == s2[i])
				h = 1;
			i++;
		}
		if (h == 1)
			def++;
		else
			break ;
		s1++;
	}
	return (def);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len_f;
	int		len_b;
	int		len_s;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	len_f = len_front(s1, set);
	len_b = len_back(s1, set);
	len_s = ft_strlen(s1) - (len_f + len_b);
	return (ft_substr(s1, len_f, len_s));
}
