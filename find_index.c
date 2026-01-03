/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapheww <rapheww@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:26:39 by rchaumei          #+#    #+#             */
/*   Updated: 2025/12/25 23:19:16 by rapheww          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	find_max(t_stack *a)
{
	int		i;
	int		max;
	int		index;
	t_stack	*tmp;

	max = a->content;
	index = 0;
	i = 0;
	tmp = a;
	while (tmp)
	{
		if (tmp->content > max)
		{
			max = tmp->content;
			index = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (index);
}

int	find_min(t_stack *a)
{
	int		i;
	int		min;
	int		index;
	t_stack	*tmp;

	min = a->content;
	index = 0;
	i = 0;
	tmp = a;
	while (tmp)
	{
		if (tmp->content < min)
		{
			min = tmp->content;
			index = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (index);
}
