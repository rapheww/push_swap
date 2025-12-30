/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapheww <rapheww@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:44:21 by rchaumei          #+#    #+#             */
/*   Updated: 2025/12/25 23:09:32 by rapheww          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_counting	*create_counting(void)
{
	t_counting	*new;

	new = malloc(sizeof(t_counting));
	if (!new)
		return (NULL);
	new->value_b = 0;
	new->count = 0;
	new->value_a = 0;
	return (new);
}

void	define_counts(int *count, t_stack *s, t_counting **counter, int i)
{
	if (i > stack_len(s) / 2)
		*count = stack_len(s) - i + 1;
	else if (i == stack_len(s) / 2)
		*count = stack_len(s) / 2;
	else
		*count = i;
}

void	count_sa(t_stack *a, t_stack *b, t_counting **counter)
{
	int	count_a;
	int	count_b;
	int	i;

	i = get_index((*counter)->value_a, a);
	define_counts(&count_a, a, counter, i);
	i = get_index((*counter)->value_b, b);
	define_counts(&count_b, b, counter, i);
	if ((get_index((*counter)->value_a, a) <= stack_len(a) / 2
			&& get_index((*counter)->value_b, b) <= stack_len(a) / 2)
		|| (get_index((*counter)->value_a, a) > stack_len(a) / 2
			&& get_index((*counter)->value_b, b) > stack_len(a) / 2))
	{
		if (count_a > count_b)
			(*counter)->count = count_a + 1;
		else
			(*counter)->count = count_b + 1;
	}
	else
		(*counter)->count = count_a + count_b + 1;
}

t_counting	*count_operations(int num, t_stack *a, t_stack *b)
{
	t_counting	*counter;
	t_stack		*tmp;

	counter = create_counting();
	if (!counter)
		return (NULL);
	counter->value_a = num;
	counter->value_b = b->content;
	tmp = b;
	if (get_min(b) < counter->value_a)
	{
		while (tmp)
		{
			if (tmp->content < num)
				if (num - tmp->content < num - counter->value_b || num
					- counter->value_b < 0)
					counter->value_b = tmp->content;
			tmp = tmp->next;
		}
	}
	else
		counter->value_b = get_max(b);
	count_sa(a, b, &counter);
	return (counter);
}

t_counting	*find_best(t_stack *a, t_stack *b)
{
	t_stack		*tmp;
	t_counting	*num;
	t_counting	*best;

	best = count_operations(a->content, a, b);
	if (!best)
		return (NULL);
	tmp = a->next;
	while (tmp)
	{
		num = count_operations(tmp->content, a, b);
		if (!num)
			return (NULL);
		if (best->count > num->count)
			best = num;
		tmp = tmp->next;
	}
	if (best->value_a < get_min(b))
		best->value_b = get_max(b);
	return (best);
}
