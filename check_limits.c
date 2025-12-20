/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_limits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 15:21:25 by rchaumei          #+#    #+#             */
/*   Updated: 2025/12/20 16:30:53 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

long	ft_atol(const char *str)
{
	int	i;
	int	signe;
	long	result;

	i = 0;
	signe = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		signe = -signe;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * signe);
}

long *ft_conv_long(int ac, char **av, int *size)
{
    int i;
    char **temp;
    long *result;
    int count;

    i = 0;
    count = 0;
    if (ac == 2)
        temp = ft_split(av[1], ' ');
    else
        temp = av + 1;
    while (temp[count])
        count++;
    result = malloc(sizeof(long) * count);
    if (!result)
        return (0);
    while (temp[i])
    {
        result[i] = ft_atol(temp[i]);
        i++;
    }
    *size = count;
    return (result);
}

int ft_check_limits(long *tab, int size)
{
    int i;

    i = 0;
    while(i < size)
    {
        if (tab[i] < -2147483648 || tab[i] > 2147483647)
            return (1);
        i++;
    }
    return (0);
}

int checks_lim(int *size, int ac, char **av)
{
    long *tab;

    tab = ft_conv_long(ac, av, size);
    if (ft_check_limits(tab, *size) == 1)
        return(1);
    return (0);
}