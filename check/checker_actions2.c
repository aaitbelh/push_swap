/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_actions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:24:34 by casper            #+#    #+#             */
/*   Updated: 2022/02/07 15:14:31 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	continue__r(t_stack *stack, char c)
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
	}
	if (c == 'r' && stack->lena && stack->lenb)
	{
		r(stack, 'a');
		r(stack, 'b');
	}
}

void	continue__rr(t_stack *stack, char c)
{
	int	i;
	int	tmp;

	if (c == 'b' && stack->lenb)
	{
		tmp = stack->b[stack->lenb - 1];
		i = stack->lenb;
		while (--i)
			stack->b[i] = stack->b[i - 1];
		stack->b[0] = tmp;
	}
	if (c == 'r' && stack->lenb && stack->lena)
	{
		rr(stack, 'a');
		rr(stack, 'b');
	}
}
