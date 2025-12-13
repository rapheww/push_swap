/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapheww <rapheww@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 18:21:12 by rapheww           #+#    #+#             */
/*   Updated: 2025/12/13 20:53:16 by rapheww          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int ft_check_sort(s_stack *s)
{
    while(s->next)
    {
        if (s->content > s->next->content)
            return (1);
        s = s->next;
    }
    return (0);
}
void ft_algo_3(s_stack **a)
{
    int i;
    int max;
    int index;
    s_stack *tmp;
    
    max = (*a)->content;
    index = 0;
    i = 0;
    tmp = *a;
    while (i < 3)
    {
        if (tmp->content > max)
        {
            max = tmp->content;
            index = i;
        }
        i++;
        tmp = tmp->next;   
    }
    if (index == 0)
        ra(a);
    else if (index == 1)
        rra(a);
    if (ft_check_sort(*a) == 1)
        sa(*a);
}

void ft_algo_4(s_stack **a, s_stack **b)
{
    int i;
    int min;
    int index;
    s_stack *tmp;
    
    min = (*a)->content;
    index = 0;
    i = 0;
    tmp = *a;
    while (i < 4)
    {
        if (tmp->content < min)
        {
            min = tmp->content;
            index = i;
        }
        i++;
        tmp = tmp->next;   
    }
    if (index == 1)
        sa(*a);
    else if (index == 2)
    {
        ra(a);
        ra(a);
    }
    else if (index == 3)
        rra(a);
    pb(a, b);
    ft_algo_3(a);
    pa(a, b);
}
