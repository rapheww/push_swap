/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:46:53 by rchaumei          #+#    #+#             */
/*   Updated: 2025/12/20 16:30:57 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

typedef struct t_stack
{
	int				content;
	struct t_stack	*next;
	// int				index;
}					s_stack;

typedef struct t_counting
{
	int				value_a;
	int				value_b;
	int				count;
}					s_counting;

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

// Create stack

s_stack				*ft_stacknew(int content);
void				ft_stackadd_front(s_stack **lst, s_stack *new);
void				ft_stackadd_back(s_stack **lst, s_stack *new);
s_stack				*ft_fill_stack(int *numbers, int size);
s_stack				*ft_stacklast(s_stack *lst);

// OPERATIONS

void				sa(s_stack *a);
void				sb(s_stack *b);
void				ss(s_stack *a, s_stack *b);
void				pa(s_stack **a, s_stack **b);
void				pb(s_stack **a, s_stack **b);
void				ra(s_stack **a);
void				rb(s_stack **b);
void				rr(s_stack **a, s_stack **b);
void				rra(s_stack **a);
void				rrb(s_stack **b);
void				rrr(s_stack **a, s_stack **b);

// ALGO

void				ft_algo_3(s_stack **a);
void				ft_algo_4(s_stack **a, s_stack **b);
void				ft_push_min(s_stack **a, s_stack **b);
void				ft_algo_5(s_stack **a, s_stack **b);
int				ft_sort_push(s_stack **a, s_stack **b);

// CHECK STACK

int					stack_len(s_stack *s);
int					find_max(s_stack *a);
int					find_min(s_stack *a);
int					ft_check_sort(s_stack *a);
int					get_min(s_stack *a);
int					get_max(s_stack *a);
int					get_index(int n, s_stack *s);
// COUNT OP

s_counting			*count_operations(int num, s_stack *a, s_stack *b);
s_counting			*create_counting(void);
s_counting			*find_best(s_stack *a, s_stack *b);

void				print_stack(s_stack *stack);
int ft_check_limits(long *tab, int size);
long *ft_conv_long(int ac, char **av, int *size);
int checks_lim(int *size, int ac, char **av);
#endif