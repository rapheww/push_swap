/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lil_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 13:00:23 by rchaumei          #+#    #+#             */
/*   Updated: 2026/01/03 12:47:26 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	choose_algo(t_stack **a, t_stack **b, int size)
{
	if (size == 0)
		return ;
	else if (size == 2)
	{
		sa(*a);
		return ;
	}
	else if (size == 3)
		ft_algo_3(a);
	else if (size == 4)
		ft_algo_4(a, b);
	else if (size == 5)
		ft_algo_5(a, b);
	else
		algo_max(a, b);
}

void	ft_push_min(t_stack **a, t_stack **b)
{
	if (find_min(*a) == 1)
		ra(a);
	else if (find_min(*a) == 2)
	{
		ra(a);
		ra(a);
	}
	else if (find_min(*a) == 3)
		rra(a);
	pb(a, b);
}

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

void	ft_algo_4(t_stack **a, t_stack **b)
{
	ft_push_min(a, b);
	ft_algo_3(a);
	pa(a, b);
}

void	ft_algo_5(t_stack **a, t_stack **b)
{
	if (find_min(*a) == 1)
		ra(a);
	else if (find_min(*a) == 2)
	{
		ra(a);
		ra(a);
	}
	else if (find_min(*a) == 3)
	{
		rra(a);
		rra(a);
	}
	else if (find_min(*a) == 4)
		rra(a);
	pb(a, b);
	ft_algo_4(a, b);
	pa(a, b);
}
