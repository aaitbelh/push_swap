/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:05:04 by aaitbelh          #+#    #+#             */
/*   Updated: 2022/02/06 18:47:47 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <limits.h>

static void	check_num(unsigned long int n, int sig)
{
	if (n > 2147483647 && sig == 1)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	if (n > 2147483648 && sig == -1)
	{
		write(1, "Error\n", 6);
		exit (0);
	}
}

int	ft_atoi(const char *str)
{
	int					i;
	int					sig;
	unsigned long int	n;

	sig = 1;
	n = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+' )
	{
		if (str[i] == '-')
			sig *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	check_num(n, sig);
	return ((int)(n * sig));
}
