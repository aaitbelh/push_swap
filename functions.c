/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:04:40 by aaitbelh          #+#    #+#             */
/*   Updated: 2022/02/05 20:01:59 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int *num)
{
	int	i;
	int	sum;
	int	a[2];

	a[0] = num[0];
	a[1] = num[1];
	i = -1;
	while (++i < 2)
		if (a[i] < 0)
			a[i] *= -1;
	sum = a[0] + a[1];
	return (sum);
}

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}
