/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:07:26 by aaitbelh          #+#    #+#             */
/*   Updated: 2022/02/05 14:39:07 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	continue_r(t_stack *stack, char c, int l)
{
	int	i;

	i = -1;
	if (c == 'b' && stack->lenb)
	{
		if (stack->lenb)
		{
			stack->tmp = stack->b[0];
			while (++i < stack->lenb - 1)
				stack->b[i] = stack->b[i + 1];
			stack->b[i] = stack->tmp;
		}
		if (l == 0)
			write(1, "rb\n", 3);
	}
	if (c == 'r')
	{
		act_r(stack, 'a', 1);
		act_r(stack, 'b', 1);
		write(1, "rr\n", 3);
	}
}

void	continue_rr(t_stack *stack, char c, int l)
{
	int	i;

	if (c == 'b' && stack->lenb)
	{
		stack->tmp = stack->b[stack->lenb - 1];
		i = stack->lenb;
		while (--i)
			stack->b[i] = stack->b[i - 1];
		stack->b[0] = stack->tmp;
		if (l == 0)
			write(1, "rrb\n", 4);
	}
	if (c == 'r')
	{
		act_rr(stack, 'a', 1);
		act_rr(stack, 'b', 1);
		write(1, "rrr\n", 4);
	}
}
