/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapheww <rapheww@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 23:14:37 by rapheww           #+#    #+#             */
/*   Updated: 2025/12/25 23:15:49 by rapheww          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rrr(t_stack **a, t_stack **b)
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
