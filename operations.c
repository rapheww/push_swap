/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 19:42:50 by rchaumei          #+#    #+#             */
/*   Updated: 2025/12/11 23:20:44 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sa(s_stack *a)
{
	int	tmp;

	if (!a || !a->next)
		return ;
	tmp = a->content;
	a->content = a->next->content;
	a->next->content = tmp;
	ft_printf("sa\n");
}
void	sb(s_stack *b)
{
	int	tmp;

	if (!b || !b->next)
		return ;
	tmp = b->content;
	b->content = b->next->content;
	b->next->content = tmp;
	ft_printf("sb\n");
}

void	ss(s_stack *a, s_stack *b)
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

void	pa(s_stack **a, s_stack **b)
{
	s_stack	*tmp;

	tmp = *b;
	*b = (*b)->next;
	tmp->next = NULL;
	ft_stackadd_front(a, tmp);
	ft_printf("pa\n");
}

void	pb(s_stack **a, s_stack **b)
{
	s_stack	*tmp;

	tmp = *a;
	*a = (*a)->next;
	tmp->next = NULL;
	ft_stackadd_front(b, tmp);
	ft_printf("pa\n");
}

void	ra(s_stack **a)
{
	s_stack	*tmp;
	s_stack	*first;

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

void	rb(s_stack **b)
{
	s_stack	*tmp;
	s_stack	*first;

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

void	rr(s_stack **a, s_stack **b)
{
	s_stack	*tmp;
	s_stack	*first;

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

void	rra(s_stack **a)
{
	s_stack	*newlast;
	s_stack	*newfirst;

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

void	rrb(s_stack **b)
{
	s_stack *newlast;
	s_stack *newfirst;

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

void rrr(s_stack **a, s_stack **b)
{
    s_stack	*newlast;
	s_stack	*newfirst;

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
    ft_printf("rrr\n");
}
