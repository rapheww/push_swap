/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapheww <rapheww@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 19:42:50 by rchaumei          #+#    #+#             */
/*   Updated: 2025/12/25 23:15:34 by rapheww          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sa(t_stack *a)
{
	int	tmp;

	if (!a || !a->next)
		return ;
	tmp = a->content;
	a->content = a->next->content;
	a->next->content = tmp;
	ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	int	tmp;

	if (!b || !b->next)
		return ;
	tmp = b->content;
	b->content = b->next->content;
	b->next->content = tmp;
	ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	int	tmpb;
	int	tmpa;

	if (b && b->next)
	{
		tmpb = b->content;
		b->content = b->next->content;
		b->next->content = tmpb;
	}
	if (a && a->next)
	{
		tmpa = a->content;
		a->content = a->next->content;
		a->next->content = tmpa;
	}
	ft_printf("ss\n");
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = *b;
	*b = (*b)->next;
	tmp->next = NULL;
	ft_stackadd_front(a, tmp);
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = *a;
	*a = (*a)->next;
	tmp->next = NULL;
	ft_stackadd_front(b, tmp);
	ft_printf("pb\n");
}
