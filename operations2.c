/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapheww <rapheww@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 23:14:17 by rapheww           #+#    #+#             */
/*   Updated: 2025/12/25 23:16:39 by rapheww          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*first;

	if (*a && (*a)->next)
	{
		first = (*a)->next;
		tmp = *a;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = *a;
		(*a)->next = NULL;
		*a = first;
	}
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*first;

	if (*b && (*b)->next)
	{
		first = (*b)->next;
		tmp = *b;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = *b;
		(*b)->next = NULL;
		*b = first;
	}
	ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*first;

	if (*a && (*a)->next)
	{
		first = (*a)->next;
		tmp = *a;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = *a;
		(*a)->next = NULL;
		*a = first;
	}
	if (*b && (*b)->next)
	{
		first = (*b)->next;
		tmp = *b;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = *b;
		(*b)->next = NULL;
		*b = first;
	}
	ft_printf("rr\n");
}

void	rra(t_stack **a)
{
	t_stack	*newlast;
	t_stack	*newfirst;

	if (*a && (*a)->next)
	{
		newlast = *a;
		while (newlast->next->next)
			newlast = newlast->next;
		newfirst = newlast->next;
		newfirst->next = *a;
		*a = newfirst;
		newlast->next = NULL;
	}
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	t_stack	*newlast;
	t_stack	*newfirst;

	if (*b && (*b)->next)
	{
		newlast = *b;
		while (newlast->next->next)
			newlast = newlast->next;
		newfirst = newlast->next;
		newfirst->next = *b;
		*b = newfirst;
		newlast->next = NULL;
	}
	ft_printf("rrb\n");
}
