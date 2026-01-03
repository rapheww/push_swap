/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:46:53 by rchaumei          #+#    #+#             */
/*   Updated: 2026/01/03 13:45:11 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

// Structure

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}					t_stack;

typedef struct s_counting
{
	int				value_a;
	int				value_b;
	int				count;
}					t_counting;

// Create stack

t_stack				*ft_stacknew(int content);
void				ft_stackadd_front(t_stack **lst, t_stack *new);
void				ft_stackadd_back(t_stack **lst, t_stack *new);
t_stack				*ft_fill_stack(int *numbers, int size);
t_stack				*ft_stacklast(t_stack *lst);

// OPERATIONS

void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);

// ALGO

void				choose_algo(t_stack **a, t_stack **b, int size);
void				ft_algo_3(t_stack **a);
void				ft_algo_4(t_stack **a, t_stack **b);
void				ft_algo_5(t_stack **a, t_stack **b);
int					algo_max(t_stack **a, t_stack **b);

// CHECK STACK

int					stack_len(t_stack *s);
int					find_max(t_stack *a);
int					find_min(t_stack *a);
int					ft_check_sort(t_stack *a);
int					get_min(t_stack *a);
int					get_max(t_stack *a);
int					get_index(int n, t_stack *s);
// COUNT OP

t_counting			*count_operations(int num, t_stack *a, t_stack *b);
t_counting			*create_counting(void);
t_counting			*find_best(t_stack *a, t_stack *b);

void				print_stack(t_stack *stack);
int					ft_check_limits(long *tab, int size);
long				*ft_conv_long(int ac, char **av, int *size);
int					checks_lim(int *size, int ac, char **av);

// FREE

void				free_all(t_stack **a);

#endif