/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 22:32:50 by casper            #+#    #+#             */
/*   Updated: 2022/02/07 18:07:29 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	free_all(t_stack *stack, char **str)
{
	int	i;

	(void ) stack;
	i = 0;
	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
	}
	free(str);
}

void	is_sorted(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < stack->lenght - 1)
		if (stack->a[i] > stack->a[i + 1])
			break ;
	if (i == stack->lena - 1)
	{
		write(1, "OK\n", 3);
		free(stack->a);
		free(stack->b);
		exit (1);
	}
}

void	ft_error(t_stack *stack)
{
	int	i;

	i = ft_strlen("error\n");
	write(2, "error\n", i);
	free(stack->a);
	free(stack->b);
	exit(1);
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
	return (1);
}
