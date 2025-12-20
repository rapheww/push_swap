/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:44:21 by rchaumei          #+#    #+#             */
/*   Updated: 2025/12/20 17:51:00 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

s_counting *create_counting(void)
{
    s_counting *new;
    
    new = malloc(sizeof(s_counting));
    if (!new)
        return (NULL);
    new->value_b = 0;
    new->count = 0;
    new->value_a = 0;
    return(new);
}

int get_min(s_stack *a)
{
    int min;
    s_stack *tmp;
    
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

int get_max(s_stack *a)
{
    int max;
    s_stack *tmp;
    
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

void count_sa(s_stack *a, s_stack *b, s_counting **counter)
{
    int count_a;
    int count_b;
    int i;
    
    i = get_index((*counter)->value_a, a);
    if (i > stack_len(a) / 2)
        count_a = stack_len(a) - i + 1;
    else if (i == stack_len(a) / 2)
        count_a = stack_len(a) / 2;
    else
        count_a = i;
    i = get_index((*counter)->value_b, b);
    if (i > stack_len(b) / 2)
        count_b = stack_len(b) - i + 1;
    else if (i == stack_len(b) / 2)
        count_b = stack_len(b) / 2;
    else
        count_b = i;
    if ((get_index((*counter)->value_a, a) <= stack_len(a) / 2 
        && get_index((*counter)->value_b, b) <= stack_len(a) / 2)
        || (get_index((*counter)->value_a, a) > stack_len(a) / 2 
        && get_index((*counter)->value_b, b) > stack_len(a) / 2))
        if (count_a > count_b)
            (*counter)->count = count_a + 1;
        else
            (*counter)->count = count_b + 1;
    else
        (*counter)->count = count_a + count_b + 1;
}

s_counting *count_operations(int num, s_stack *a, s_stack *b)
{
    s_counting *counter;
    s_stack *tmp;

    counter = create_counting();
    if (!counter)
        return (NULL);
    counter->value_a = num;
    counter->value_b = b->content;
    tmp = b;
    if (get_min(b) < counter->value_a)
    {
        while(tmp)
        {
            if (tmp->content < num)
                if (num - tmp->content < num - counter->value_b || num - counter->value_b < 0)
                    counter->value_b = tmp->content;
            tmp = tmp->next;
        }
    }
    else
        counter->value_b = get_max(b);
    count_sa(a, b, &counter);
    return (counter);
}

s_counting *find_best(s_stack *a, s_stack *b)
{
    s_stack *tmp;
    s_counting *num;
    s_counting *best;

    best = count_operations(a->content, a, b);
    if (!best)
        return (NULL);
    tmp = a->next;
    while(tmp)
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
