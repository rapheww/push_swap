/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:28:33 by rchaumei          #+#    #+#             */
/*   Updated: 2026/01/03 15:02:06 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdio.h>

int	ft_verif_arg(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '-' || av[i][j] == '+')
			{
				if (j != 0 && av[i][j - 1] != 32)
					return (1);
				if (av[i][j + 1] == '\0' || (av[i][j + 1] < '0' || av[i][j
						+ 1] > '9'))
					return (1);
			}
			else if ((av[i][j] < '0' || av[i][j] > '9') && av[i][j] != ' ')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*ft_conv(int ac, char **av, int *size)
{
	int		i;
	char	**temp;
	int		*result;
	int		count;

	i = -1;
	count = 0;
	if (ac == 2)
	{
		temp = ft_split(av[1], ' ');
		if (!temp)
			return (NULL);
	}
	else
		temp = av + 1;
	while (temp[count])
		count++;
	result = malloc(sizeof(int) * count);
	if (!result)
		return (NULL);
	while (temp[++i])
		result[i] = ft_atoi(temp[i]);
	*size = count;
	return (result);
}

int	ft_check_duplicate(int *numbers, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (numbers[i] == numbers[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_sort(t_stack *s)
{
	while (s->next)
	{
		if (s->content > s->next->content)
			return (1);
		s = s->next;
	}
	return (0);
}

void	print_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
}

int	main(int ac, char **av)
{
	int		*numbers;
	int		size;
	t_stack	*b;
	t_stack	*a;

	if (ac < 2 || (ac >= 2 && ft_verif_arg(av)) || checks_lim(&size, ac, av))
		return (ft_printf("Error\n"), 0);
	numbers = ft_conv(ac, av, &size);
	if (!numbers)
		return (0);
	if (ft_check_duplicate(numbers, size) == 1)
		return (free(numbers), ft_printf("Error\n"), 0);
	a = ft_fill_stack(numbers, size);
	if (!a)
		return (free(numbers), 0);
	b = NULL;
	if (ft_check_sort(a) == 0)
		return (free_all(&a), free(numbers), 0);
	choose_algo(&a, &b, size);
	free_all(&a);
	free_all(&b);
	free(numbers);
	return (0);
}
