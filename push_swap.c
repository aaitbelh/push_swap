/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:04:52 by aaitbelh          #+#    #+#             */
/*   Updated: 2022/02/07 18:09:02 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_all(t_stack *stack)
{
	free(stack->a);
	free(stack->b);
	free(stack->t);
	free(stack->saver);
	exit (1);
}

static void	declaration(t_stack *stack, char **av, int ac)
{
	int	i;

	i = -1;
	while (++i < ac - 1)
		stack->a[i] = ft_atoi(av[i + 1]);
	if (!check_dup(stack))
	{
		write(2, "error\n", 6);
		free_all(stack);
	}
	get_index(stack);
	if (ac == 3)
	{
		act_s(stack, 'a', 0);
		free(stack->a);
		free(stack->b);
		exit(0);
	}
	if (ac == 4)
	{
		sort_three(stack);
		free(stack->a);
		free(stack->b);
		exit(0);
	}
}

void	get_index(t_stack *stack)
{
	int	i;
	int	j;
	int	*tmp;

	i = -1;
	tmp = malloc(sizeof(int ) * stack->lena);
	while (++i < stack->lena)
		tmp[i] = stack->a[i];
	ft_sort(tmp, stack->lena);
	i = -1;
	while (++i < stack->lena)
	{
		j = -1;
		while (++j < stack->lena)
		{
			if (tmp[j] == stack->a[i])
			{
				stack->a[i] = j;
				break ;
			}
		}
	}
	free(tmp);
}

int	main(int ac, char **av)
{
	t_stack	stack;

	if (ac < 2)
		exit(1);
	if (!is_int(av))
	{
		write(2, "error\n", 6);
		exit(0);
	}
	stack.lena = ac - 1;
	stack.ln = ac - 1;
	stack.lenb = 0;
	stack.a = malloc(sizeof(int ) * ac - 1);
	stack.b = malloc(sizeof(int ) * ac - 1);
	declaration(&stack, av, ac);
	stack.saver = malloc(sizeof(int ) * 2);
	stack.t = malloc(sizeof(int ) * 2);
	while (stack.lena > 3)
	{
		get_best(&stack);
		push_b(&stack);
	}
	if (stack.lena <= 3)
		push_higher(&stack);
	free_all(&stack);
}
