/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:38:37 by rchaumei          #+#    #+#             */
/*   Updated: 2025/12/17 18:46:57 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

s_stack *ft_fill_stack(int *numbers, int size)
{
    int i;
    s_stack *a;

    i = 0;
    a = ft_stacknew(numbers[i]);
    i++;
    while(i < size)
    {
        ft_stackadd_back(&a, ft_stacknew(numbers[i]));
        i++;
    }
    return (a);
}
