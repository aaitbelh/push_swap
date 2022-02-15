/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:44:31 by aaitbelh          #+#    #+#             */
/*   Updated: 2022/02/05 20:09:22 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(int *tmp, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (tmp[i] > tmp[j])
				ft_swap(&tmp[i], &tmp[j]);
			j++;
		}
		i++;
	}
}

int	big_element(t_stack *stack)
{
	int	tmp[2];
	int	i;

	i = 0;
	tmp[0] = stack->b[0];
	tmp[1] = 0;
	while (++i < stack->lenb)
	{
		if (tmp[0] < stack->b[i])
		{
			tmp[0] = stack->b[i];
			tmp[1] = i;
		}
	}
	return (tmp[1]);
}
