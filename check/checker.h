/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitbelh <aaitbelh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:18:18 by aaitbelh          #+#    #+#             */
/*   Updated: 2022/02/06 20:23:37 by aaitbelh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# define BUFFER_SIZE 10000

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct v_stack
{
	int		*a;
	int		*b;
	char	*s;
	int		lena;
	int		lenb;
	int		tmp;
	char	*t;
	int		lenght;
}	t_stack;
//------------------------define functions------------------------------------
int		check_dup(t_stack *stack);
void	ft_error(t_stack *stack);
void	is_sorted(t_stack *stack);
int		ft_atoi(const char *str);
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
int		ft_strcmp(const char	*s1, const char *s2);
void	ft_swap(int *a, int *b);
int		check_dup(t_stack *stack);
void	ft_error(t_stack *stack);
void	is_sorted(t_stack *stack);
void	free_all(t_stack *stack, char **str);
//----------------------------------------Checker_tools-----------------------
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char *str, int c);
int		ft_strlen(char *str);
char	*ft_strdup(const char	*src);
//------------------------------------actions---------------------------------
void	s(t_stack *stack, char c);
void	p(t_stack *stack, char c);
void	r(t_stack *stack, char c);
void	rr(t_stack *stack, char c);
void	make__a(t_stack *stack);
void	fix__b(t_stack *stack);
void	make__b(t_stack *stack);
void	fix__a(t_stack *stack);
void	continue__best_b(t_stack *s, int *tmp, int b);
void	continue__r(t_stack *stack, char c);
void	continue__rr(t_stack *stack, char c);
int		is_int(char **str);
int		ft_isdigit(int c);

#endif