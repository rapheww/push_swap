/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapheww <rapheww@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:28:33 by rchaumei          #+#    #+#             */
/*   Updated: 2025/12/13 20:51:53 by rapheww          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdio.h>

int ft_verif_arg(char **av)
{
    int i;
    int j;

    i = 1;
    while (av[i])
    {
        j = 0;
        while (av[i][j])
        {
            if (av[i][j] == '-' || av[i][j] == '+')
            {
                if(av[i][j+1] == '\0' || (av[i][j+1] < '0' || av[i][j+1] > '9'))
                    return(1);
            }
            else if ((av[i][j] < '0' || av[i][j] > '9') && av[i][j] != ' ')
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int *ft_conv(int ac, char **av, int *size)
{
    int i;
    char **temp;
    int *result;
    int count;

    i = 0;
    count = 0;
    if (ac == 2)
        temp = ft_split(av[1], ' ');
    else
        temp = av + 1;
    while (temp[count])
        count++;
    result = malloc(sizeof(int ) * count);
    if (!result)
        return (NULL);
    while (temp[i])
    {
        result[i] = ft_atoi(temp[i]);
        i++;
    }
    *size = count;
    return (result);
}


int ft_check_duplicate(int *numbers, int size)
{
    int i;
    int j;

    i = 0;
    while (i < size)
    {
        j = i + 1;
        while(j < size)
        {
            if (numbers[i] == numbers[j])
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

void    print_stack(s_stack *stack)
{
    s_stack *tmp = stack;

    while (tmp)
    {
        printf("%d\n", tmp->content);
        tmp = tmp->next;
    }
}


int main(int ac, char **av)
{
    int *numbers;
    int size;
    s_stack *a;
    s_stack *b;
    if (ac < 2 || (ac >= 2 && ft_verif_arg(av) != 0))
        return (ft_printf("Error\n"),0);
    numbers = ft_conv(ac, av, &size);
    if (ft_check_duplicate(numbers, size) == 1)
        return (ft_printf("Error\n"),0);
    a = ft_fill_stack(numbers, size);
    b = NULL;
    if (ft_check_sort(a) == 0)
        return (0);
    if (size == 2)
        return(sa(a),0);
    if (size == 3)
        return(ft_algo_3(&a), 0);
    if (size == 4)
        return(ft_algo_4(&a ,&b), 0);
    return (0);
}
