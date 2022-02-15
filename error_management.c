/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 22:56:33 by aaitbelh          #+#    #+#             */
/*   Updated: 2022/02/07 11:20:40 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_sorted(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < stack->lena - 1)
		if (stack->a[i] > stack->a[i + 1])
			break ;
	if (i == stack->lena - 1)
	{
		free(stack->a);
		free(stack->b);
		exit (1);
	}
}

int	is_int(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == ' ' || str[i][j] == '+' || str[i][j] == '-')
				j++;
			if (!ft_isdigit(str[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_dup(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->lena)
	{
		j = i + 1;
		while (j < stack->lena && stack->a[j] != stack->a[i])
			j++;
		if (stack->a[i] == stack->a[j])
			return (0);
		i++;
	}
	is_sorted(stack);
	return (1);
}
