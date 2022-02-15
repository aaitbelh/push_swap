/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:04:24 by aaitbelh          #+#    #+#             */
/*   Updated: 2022/02/05 14:57:40 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	act_s(t_stack *stack, char c, int i)
{
	if (c == 'a' && stack->lena)
	{
		ft_swap(&(stack->a[0]), &(stack->a[1]));
		if (i == 0)
			write(1, "sa\n", 3);
	}
	if (c == 'b')
	{
		ft_swap(&(stack->b[0]), &(stack->b[1]));
		if (i == 0)
			write(1, "sb\n", 3);
	}
	if (c == 's')
	{
		act_s(stack, 'a', 1);
		act_s(stack, 'b', 1);
		write(1, "ss\n", 3);
	}
}

void	act_p(t_stack *stack, char c)
{
	if (c == 'a' && stack->lenb)
	{
		stack->tmp = stack->a[0];
		stack->a[0] = stack->b[0];
		stack->lena++;
		make_a(stack);
		stack->lenb--;
		fix_b(stack);
		write(1, "pa\n", 3);
	}
	if (c == 'b' && stack->lena)
	{
		stack->tmp = stack->b[0];
		stack->b[0] = stack->a[0];
		stack->lenb++;
		make_b(stack);
		stack->lena--;
		fix_a(stack);
		write(1, "pb\n", 3);
	}
}

void	act_r(t_stack *stack, char c, int l)
{
	int	i;

	i = -1;
	if (c == 'a' && stack->lena)
	{
		stack->tmp = stack->a[0];
		while (++i < stack->lena - 1)
			stack->a[i] = stack->a[i + 1];
		stack->a[i] = stack->tmp;
		if (l == 0)
			write(1, "ra\n", 3);
	}
	continue_r(stack, c, l);
}

void	act_rr(t_stack *stack, char c, int l)
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
		if (l == 0)
			write(1, "rra\n", 4);
	}
	continue_rr(stack, c, l);
}
