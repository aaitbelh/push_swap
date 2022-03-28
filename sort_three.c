/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:59:26 by aaitbelh          #+#    #+#             */
/*   Updated: 2022/02/06 12:56:05 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_all(t_stack *stack)
{
	while (stack->lenb)
		act_p(stack, 'a');
}

void	push_higher(t_stack *stack)
{
	int	i;
	int	n;

	n = big_element(stack);
	i = -1;
	if (n < stack->lenb / 2)
	{
		while (++i < n)
			act_r(stack, 'b', 0);
	}
	else
	{
		n -= stack->lenb;
		while (++i < n * -1)
			act_rr(stack, 'b', 0);
	}
	sort_three(stack);
	push_all(stack);
}

void	sort_three(t_stack *stack)
{
	if (stack->a[0] < stack->a[1] && stack->a[0] < stack->a[2]
		&& stack->a[1] > stack->a[2])
	{
		act_s(stack, 'a', 0);
		act_r(stack, 'a', 0);
	}
	else if (stack->a[0] > stack->a[1] && stack->a[0] > stack->a[2]
		&& stack->a[1] < stack->a[2])
		act_r(stack, 'a', 0);
	else if (stack->a[0] > stack->a[1] && stack->a[0] < stack->a[2]
		&& stack->a[2] > stack->a[1])
		act_s (stack, 'a', 0);
	else if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[2])
		act_rr(stack, 'a', 0);
	else if (stack->a[0] > stack->a[1] && stack->a[0] > stack->a[2])
	{
		act_s(stack, 'a', 0);
		act_rr(stack, 'a', 0);
	}
}
