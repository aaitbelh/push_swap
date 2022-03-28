/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 20:07:57 by aaitbelh          #+#    #+#             */
/*   Updated: 2022/02/05 22:08:12 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	continue_push_x(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < stack->saver[1])
		act_r(stack, 'r', 1);
	stack->saver[0] -= i;
		i = -1;
	while (++i < stack->saver[0])
		act_r(stack, 'a', 0);
}

static void	continue_push(t_stack *stack)
{
	int	i;

	i = -1;
	if (stack->saver[0] >= stack->saver[1])
	{
		while (++i < stack->saver[0] * -1)
			act_rr(stack, 'r', 1);
		stack->saver[1] += i;
		i = -1;
		while (++i < stack->saver[1] * -1)
			act_rr(stack, 'b', 0);
	}
	else if (stack->saver[1] >= stack->saver[0])
	{
		while (++i < stack->saver[1] * -1)
			act_rr(stack, 'r', 1);
		stack->saver[0] += i;
		i = -1;
		while (++i < stack->saver[0] * -1)
			act_rr(stack, 'a', 0);
	}
}

static void	push_x(t_stack *stack, int x)
{
	int	i;

	i = -1;
	if (x == 1)
	{
		if (stack->saver[0] <= stack->saver[1])
		{
			while (++i < stack->saver[0])
				act_r(stack, 'r', 1);
			stack->saver[1] -= i;
			i = -1;
			while (++i < stack->saver[1])
				act_r(stack, 'b', 0);
		}
		else if (stack->saver[1] <= stack->saver[0])
			continue_push_x(stack);
	}
	else if (x == 2)
		continue_push(stack);
}

void	push_b(t_stack *stack)
{
	int	i;

	i = -1;
	if (stack->saver[0] >= 0 && stack->saver[1] <= 0)
	{
		while (++i < stack->saver[0])
			act_r(stack, 'a', 0);
		i = -1;
		while (++i < stack->saver[1] * -1)
			act_rr(stack, 'b', 0);
	}
	else if (stack->saver[1] >= 0 && stack->saver[0] <= 0)
	{
		while (++i < stack->saver[0] * -1)
			act_rr(stack, 'a', 0);
		i = -1;
		while (++i < stack->saver[1])
			act_r(stack, 'b', 0);
	}
	else if (stack->saver[1] >= 0 && stack->saver[0] >= 0)
		push_x(stack, 1);
	else if (stack->saver[1] <= 0 && stack->saver[0] <= 0)
		push_x(stack, 2);
	act_p(stack, 'b');
}
