/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:44:21 by rchaumei          #+#    #+#             */
/*   Updated: 2025/12/18 15:09:21 by rchaumei         ###   ########.fr       */
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

void count_sa(int num, s_stack *s, s_counting **counter)
{
    int i;
    s_stack *tmp;
    int len;

    i = 0;
    len = stack_len(s);
    tmp = s;
    while (tmp && tmp->content != num)
    {
        tmp = tmp->next;
        i++;
    }
    if (i > len / 2)
        (*counter)->count += len - i + 1;
    else if (i == len / 2)
        (*counter)->count += len / 2;
    else
        (*counter)->count += i;
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
    count_sa(counter->value_a, a, &counter);
    count_sa(counter->value_b, b, &counter);
    counter->count += 1;
    return (counter);
}

s_counting *find_best(s_stack *a, s_stack *b)
{
    s_stack *tmp;
    s_counting *num;
    s_counting *best;

    best = count_operations(a->content, a, b);
    tmp = a->next;
    while(tmp)
    {
        num = count_operations(tmp->content, a, b);
        if (best->count > num->count)
            best = num;
        tmp = tmp->next;
    }
    if (best->value_a < get_min(b))
            best->value_b = get_max(b);
    return (best);
}
