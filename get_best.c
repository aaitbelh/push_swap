/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_best.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:07:43 by aaitbelh          #+#    #+#             */
/*   Updated: 2022/02/07 12:14:17 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	continue_get_b(t_stack *stack, int i)
{
	if (stack->a[i] > stack->b[0]
		&& stack->a[i] < stack->b[stack->lenb - 1])
		stack->t[1] = 0;
	else
	{
		if (big_element(stack) <= stack->lenb / 2)
			stack->t[1] = big_element(stack);
		else
			stack->t[1] = big_element(stack) - stack->lenb;
	}
}

void	get_b(t_stack *stack, int i)
{
	int	b;

	b = -1;
	if (!stack->lenb || stack->lenb <= 1)
		stack->t[1] = 0;
	else
	{
		while (++b < stack->lenb - 1)
		{
			if (stack->a[i] < stack->b[b] && stack->a[i] > stack->b[b + 1])
			{
				if (b <= stack->lenb / 2)
					stack->t[1] = b + 1;
				else
					stack->t[1] = b - stack->lenb + 1;
				return ;
			}
		}
		if (stack->a[i] > stack->b[0]
			&& stack->a[i] < stack->b[stack->lenb - 1])
			stack->t[1] = 0;
		else
			continue_get_b(stack, i);
	}
}

void	get_a(t_stack *stack, int i)
{
	if (i <= stack->lena / 2)
		stack->t[0] = i;
	else
		stack->t[0] = i - stack->lena;
}

void	get_best(t_stack *stack)
{
	int	i;
	int	tmp[2];

	i = 0;
	tmp[0] = 10000;
	tmp[1] = 10000;
	while (i < stack->lena - 1)
	{
		while (stack->a[i] >= stack->ln - 3 && i < stack->lena - 1)
			i++;
		if (!(i == stack->lena - 1 && stack->a[i] >= stack->ln - 3))
		{
			get_a(stack, i);
			get_b(stack, i);
			if (ft_abs(&tmp[0]) > ft_abs(stack->t))
			{
				tmp[0] = stack->t[0];
				tmp[1] = stack->t[1];
			}
		}
		i++;
	}
	stack->saver[0] = tmp[0];
	stack->saver[1] = tmp[1];
}
