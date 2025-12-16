/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 18:21:12 by rapheww           #+#    #+#             */
/*   Updated: 2025/12/16 16:04:21 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void ft_push_min(s_stack **a, s_stack **b)
{
    int index;

    index = find_min(*a);
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
}

void ft_algo_3(s_stack **a)
{
    int index;

    index = find_max(*a);
    if (index == 0)
        ra(a);
    else if (index == 1)
        rra(a);
    if (ft_check_sort(*a) == 1)
        sa(*a);
}

void ft_algo_4(s_stack **a, s_stack **b)
{
    ft_push_min(a, b);
    ft_algo_3(a);
    pa(a, b);
}

void ft_algo_5(s_stack **a, s_stack **b)
{
    ft_push_min(a, b);
    ft_push_min(a,b);
    ft_algo_3(a);
    if (ft_check_sort(*b) == 0)
        sb(*b);
    pa(a, b);
    pa(a, b);
}

int stack_len(s_stack *s)
{
    int i;
    
    i = 0;
    while (s && s->next)
    {
        i++;
        s = s->next;
    }
    return (i);
}

// void ft_algo_max(s_stack **a, s_stack **b)
// {
//     int min;
//     s_stack *tmp;
//     int size;
    

//     while(*a)
//     {
//         tmp = *a;
//         min = tmp->content;
//         while(tmp)
//         {
//             if (min > tmp->content)
//                 min = tmp->content;
//             tmp = tmp->next;
//         }
//         size = stack_len(*a);
//         if (*a && find_min(*a) < size / 2)
//         {
//             while ((*a)->content != min)
//                 ra(a);
//         }
//         else 
//         {
//             while((*a)->content != min)
//                 rra(a);
//         }
//         pb(a,b);
//     }
//     while(*b)
//         pa(a, b);
// }
