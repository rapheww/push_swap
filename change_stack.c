/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:44:03 by rchaumei          #+#    #+#             */
/*   Updated: 2026/01/03 13:57:49 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*ft_stacknew(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_stackadd_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}

void	ft_stackadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_stacklast(*lst);
	last->next = new;
}

t_stack	*ft_stacklast(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_stack	*ft_fill_stack(int *numbers, int size)
{
	int		i;
	t_stack	*a;
	t_stack	*tmp;

	i = 0;
	a = ft_stacknew(numbers[i]);
	if (!a)
		return (free(a), NULL);
	i++;
	while (i < size)
	{
		tmp = ft_stacknew(numbers[i]);
		if (!tmp)
		{
			free(tmp);
			free_all(&a);
			return (NULL);
		}
		ft_stackadd_back(&a, tmp);
		i++;
	}
	return (a);
}
