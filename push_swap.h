/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:05:01 by aaitbelh          #+#    #+#             */
/*   Updated: 2022/02/06 10:28:53 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	*saver;
	int	lena;
	int	lenb;
	int	tmp;
	int	*t;
	int	ln;
	int	success;
}	t_stack;

void	act_s(t_stack *stack, char c, int i);
void	act_p(t_stack *stack, char c);
void	act_r(t_stack *stack, char c, int l);
void	act_r(t_stack *stack, char c, int l);
void	act_rr(t_stack *stack, char c, int l);
void	continue_r(t_stack *stack, char c, int l);
void	continue_rr(t_stack *stack, char c, int l);
void	get_index(t_stack *stack);
int		ft_atoi(const char *str);
int		ft_abs(int	*num);
void	make_a(t_stack *stack);
void	fix_b(t_stack *stack);
void	make_b(t_stack *stack);
void	fix_a(t_stack *stack);
void	ft_swap(int *a, int *b);
void	ft_sort(int *tmp, int len);
int		big_element(t_stack *stack);
void	get_b(t_stack *stack, int i);
void	get_a(t_stack *stack, int i);
void	get_best(t_stack *stack);
void	push_b(t_stack *stack);
void	sort_three(t_stack *stack);
void	push_all(t_stack *stack);
void	push_higher(t_stack *stack);
int		check_dup(t_stack *stack);
int		is_int(char **str);
void	is_sorted(t_stack *stack);
int		ft_isdigit(int c);

#endif