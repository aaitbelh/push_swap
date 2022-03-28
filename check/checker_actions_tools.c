/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_actions_tools.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casper <casper@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:28:27 by casper            #+#    #+#             */
/*   Updated: 2022/01/22 15:37:07 by casper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	make__a(t_stack *stack)
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

void	fix__b(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->lenb)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
}

void	make__b(t_stack *stack)
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

void	fix__a(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->lena)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
}
