/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:26:39 by rchaumei          #+#    #+#             */
/*   Updated: 2025/12/18 15:09:27 by rchaumei         ###   ########.fr       */
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

int find_max(s_stack *a)
{
    int i;
    int max;
    int index;
    s_stack *tmp;
    
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
    return(index);
}

int find_min(s_stack *a)
{
    int i;
    int min;
    int index;
    s_stack *tmp;
    
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

int get_index(int n, s_stack *s)
{
    int i;

    i = 0;
    while(s && s->content != n)
    {
        i++;
        s = s->next;
    }
    return (i);
}