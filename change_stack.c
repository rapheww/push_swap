/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:44:03 by rchaumei          #+#    #+#             */
/*   Updated: 2025/12/17 18:46:08 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

s_stack	*ft_stacknew(int content)
{
	s_stack	*new;

	new = malloc(sizeof(s_stack));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_stackadd_front(s_stack **lst, s_stack *new)
{
	new->next = *lst;
	*lst = new;
}

void	ft_stackadd_back(s_stack **lst, s_stack *new)
{
	s_stack	*last;

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

s_stack	*ft_stacklast(s_stack *lst)
 {
 	if (lst == NULL)
 		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}