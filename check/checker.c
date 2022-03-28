/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:06:37 by casper            #+#    #+#             */
/*   Updated: 2022/02/07 18:07:18 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_result(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->lena - 1 && stack->a[i] < stack->a[i + 1])
		i++;
	if (i == stack->lenght - 1)
		write(1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	exit (1);
}

static void	continue_do_it(t_stack *stack, char **op, int i)
{
	if (!ft_strcmp(op[i], "ra"))
		r(stack, 'a');
	else if (!ft_strcmp(op[i], "rb"))
		r(stack, 'b');
	else if (!ft_strcmp(op[i], "rr"))
		r(stack, 'r');
	else if (!ft_strcmp(op[i], "rra"))
		rr(stack, 'a');
	else if (!ft_strcmp(op[i], "rrb"))
		rr(stack, 'b');
	else if (!ft_strcmp(op[i], "rrr"))
		rr(stack, 'r');
	else
	{
		write (2, "error\n", 6);
		free_all(stack, op);
		exit (1);
	}
}

static void	do_it(t_stack *stack, char **op)
{
	int	i;

	i = 0;
	while (op[i])
	{
		if (!ft_strcmp(op[i], "sa"))
			s(stack, 'a');
		else if (!ft_strcmp(op[i], "sb"))
			s(stack, 'b');
		else if (!ft_strcmp(op[i], "ss"))
			s(stack, 's');
		else if (!ft_strcmp(op[i], "pa"))
			p(stack, 'a');
		else if (!ft_strcmp(op[i], "pb"))
			p(stack, 'b');
		else
			continue_do_it(stack, op, i);
		i++;
	}
}

static void	ft_get_op(t_stack *stack)
{
	char	*tmp;
	char	**operations;

	while (1)
	{
		tmp = get_next_line(0);
		if (!tmp)
			break ;
		stack->t = ft_strjoin(stack->t, tmp);
		free(tmp);
	}
	if (!stack->t)
		ft_result(stack);
	operations = ft_split(stack->t, '\n');
	free(stack->t);
	do_it(stack, operations);
	free_all(stack, operations);
}

int	main(int ac, char **av)
{
	t_stack	stack;
	int		i;

	if (ac <= 1)
		exit(1);
	stack.a = malloc(sizeof(int ) * ac - 1);
	stack.b = malloc(sizeof(int ) * ac - 1);
	stack.lenb = 0;
	stack.lena = ac - 1;
	stack.lenght = ac - 1;
	i = -1;
	while (++i < stack.lena)
		stack.a[i] = ft_atoi(av[i + 1]);
	if (!check_dup(&stack) || !is_int(av))
		ft_error(&stack);
	ft_get_op(&stack);
	ft_result(&stack);
	return (0);
}
