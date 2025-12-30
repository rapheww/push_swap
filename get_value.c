/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapheww <rapheww@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 23:09:22 by rapheww           #+#    #+#             */
/*   Updated: 2025/12/25 23:20:14 by rapheww          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	get_min(t_stack *a)
{
	int		min;
	t_stack	*tmp;

	min = a->content;
	tmp = a;
	while (tmp)
	{
		if (tmp->content < min)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

int	get_max(t_stack *a)
{
	int		max;
	t_stack	*tmp;

	max = a->content;
	tmp = a;
	while (tmp)
	{
		if (tmp->content > max)
			max = tmp->content;
		tmp = tmp->next;
	}
	return (max);
}

int	get_index(int n, t_stack *s)
{
	int	i;

	i = 0;
	while (s && s->content != n)
	{
		i++;
		s = s->next;
	}
	return (i);
}
