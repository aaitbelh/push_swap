/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:24:05 by casper            #+#    #+#             */
/*   Updated: 2022/02/06 16:54:16 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	s(t_stack *stack, char c)
{
	if (c == 'a' && stack->lena)
		ft_swap(&(stack->a[0]), &(stack->a[1]));
	if (c == 'b')
		ft_swap(&(stack->b[0]), &(stack->b[1]));
	if (c == 's' && stack->lena && stack->lenb)
	{
		s(stack, 'a');
		s(stack, 'b');
	}
}

void	p(t_stack *stack, char c)
{
	if (c == 'a' && stack->lenb)
	{
		stack->tmp = stack->a[0];
		stack->a[0] = stack->b[0];
		stack->lena++;
		make__a(stack);
		stack->lenb--;
		fix__b(stack);
	}
	if (c == 'b' && stack->lena)
	{
		stack->tmp = stack->b[0];
		stack->b[0] = stack->a[0];
		stack->lenb++;
		make__b(stack);
		stack->lena--;
		fix__a(stack);
	}
}

void	r(t_stack *stack, char c)
{
	int	i;

	i = -1;
	if (c == 'a' && stack->lena)
	{
		stack->tmp = stack->a[0];
		while (++i < stack->lena - 1)
			stack->a[i] = stack->a[i + 1];
		stack->a[i] = stack->tmp;
	}
	continue__r(stack, c);
}

void	rr(t_stack *stack, char c)
{
	int	i;
	int	tmp;

	if (c == 'a' && stack->lena)
	{
		i = stack->lena;
		tmp = stack->a[stack->lena - 1];
		while (--i)
			stack->a[i] = stack->a[i - 1];
		stack->a[i] = tmp;
	}
	continue__rr(stack, c);
}
