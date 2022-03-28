/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:02:58 by aaitbelh          #+#    #+#             */
/*   Updated: 2022/02/07 14:03:31 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*get_next_line(int fd)
{
	char	line[8000000];
	char	c;
	int		i;

	i = -1;
	while (++i < 8000000)
		line[i] = 0;
	i = 0;
	while (read(fd, &c, 1) > 0)
	{
		line[i++] = c;
		if (c == '\n')
			break ;
	}
	if (line[0] == 0)
		return (NULL);
	return (ft_strdup(line));
}
