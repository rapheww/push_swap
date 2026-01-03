/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 18:21:12 by rapheww           #+#    #+#             */
/*   Updated: 2026/01/03 15:01:59 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	stack_len(t_stack *s)
{
	int	i;

	i = 0;
	while (s)
	{
		i++;
		s = s->next;
	}
	return (i);
}

void	ft_rrr(t_counting *best, t_stack **a, t_stack **b)
{
	if ((*a)->next && (*a)->next->content == best->value_a)
		sa(*a);
	if (*a && get_index(best->value_a, *a) <= stack_len(*a) / 2
		&& (*a)->content != best->value_a)
	{
		if (*b && get_index(best->value_b, *b) <= stack_len(*b) / 2
			&& (*b)->content != best->value_b)
		{
			while ((*a)->content != best->value_a
				&& (*b)->content != best->value_b)
				rr(a, b);
		}
	}
	if (*a && get_index(best->value_a, *a) > stack_len(*a) / 2
		&& (*a)->content != best->value_a)
	{
		if (*b && get_index(best->value_b, *b) > stack_len(*b) / 2
			&& (*b)->content != best->value_b)
		{
			while ((*a)->content != best->value_a
				&& (*b)->content != best->value_b)
				rrr(a, b);
		}
	}
}

void	ft_rotate(t_counting *best, t_stack **a, t_stack **b)
{
	if (*a && get_index(best->value_a, *a) > stack_len(*a) / 2
		&& (*a)->content != best->value_a)
	{
		while ((*a)->content != best->value_a)
			rra(a);
	}
	else
	{
		while ((*a)->content != best->value_a)
			ra(a);
	}
	if (*b && get_index(best->value_b, *b) > stack_len(*b) / 2
		&& (*b)->content != best->value_b)
	{
		while ((*b)->content != best->value_b)
			rrb(b);
	}
	else
	{
		while ((*b)->content != best->value_b)
			rb(b);
	}
}

int	algo_max(t_stack **a, t_stack **b)
{
	t_counting	*best;

	pb(a, b);
	pb(a, b);
	while (*a)
	{
		best = find_best(*a, *b);
		if (!best)
			return (free(best), 0);
		ft_rrr(best, a, b);
		ft_rotate(best, a, b);
		pb(a, b);
		free(best);
	}
	if (find_max(*b) > stack_len(*b) / 2)
		while ((*b)->content != get_max(*b))
			rrb(b);
	else
		while ((*b)->content != get_max(*b))
			rb(b);
	while (*b)
		pa(a, b);
	return (1);
}
