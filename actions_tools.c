/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:21:21 by aaitbelh          #+#    #+#             */
/*   Updated: 2022/02/02 16:46:54 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_a(t_stack *stack)
{
	int	i;
	int	tmp2;

	i = 1;
	while (i < stack->lena)
	{
		tmp2 = stack->a[i];
		stack->a[i] = stack->tmp;
		stack->tmp = tmp2;
		i++;
	}
}

void	fix_b(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->lenb)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
}

void	make_b(t_stack *stack)
{
	int	i;
	int	tmp2;

	i = 1;
	while (i < stack->lenb)
	{
		tmp2 = stack->b[i];
		stack->b[i] = stack->tmp;
		stack->tmp = tmp2;
		i++;
	}
}

void	fix_a(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->lena)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
}
