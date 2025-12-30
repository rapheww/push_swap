/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapheww <rapheww@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 18:21:12 by rapheww           #+#    #+#             */
/*   Updated: 2025/12/25 23:13:11 by rapheww          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_algo_3(t_stack **a)
{
	int	index;

	index = find_max(*a);
	if (index == 0)
		ra(a);
	else if (index == 1)
		rra(a);
	if (ft_check_sort(*a) == 1)
		sa(*a);
}

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

int	algo_max(t_stack **a, t_stack **b)
{
	t_counting	*best;

	pb(a, b);
	pb(a, b);
	while (*a)
	{
		best = find_best(*a, *b);
		if (!best)
			return (0);
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
		pb(a, b);
	}
	while ((*b)->content != get_max(*b))
		rb(b);
	while (*b)
		pa(a, b);
	return (1);
}
