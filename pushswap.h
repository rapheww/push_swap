/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:46:53 by rchaumei          #+#    #+#             */
/*   Updated: 2025/12/11 23:00:39 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

typedef struct t_stack
{
	int				content;
	struct t_stack	*next;
}					s_stack;

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

s_stack				*ft_stacknew(int content);
// void	ft_lstiter(s_stack *lst, void (*f)(void *));
void	ft_stackadd_front(s_stack **lst, s_stack *new);
void				ft_stackadd_back(s_stack **lst, s_stack *new);
s_stack				*ft_fill_stack(int *numbers, int size);
s_stack	*ft_stacklast(s_stack *lst);

//OPERATIONS

void	sa(s_stack *a);
void	sb(s_stack *b);
void	ss(s_stack *a, s_stack *b);
void	pa(s_stack **a, s_stack **b);
void	pb(s_stack **a, s_stack **b);
void	ra(s_stack **a);
void	rb(s_stack **b);
void	rr(s_stack **a, s_stack **b);
void	rra(s_stack **a);
void	rrb(s_stack **b);
void rrr(s_stack **a, s_stack **b);

#endif