/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <fford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 17:17:17 by fford             #+#    #+#             */
/*   Updated: 2020/08/25 20:50:33 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static int	is_double(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size_a)
	{
		j = i + 1;
		while (j < stack->size_a)
		{
			if (stack->stack_a[i] == stack->stack_a[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ps_atoi(t_stack *stack, const char *str)
{
	int			i;
	int			sign;
	long		num;

	i = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\r')\
			|| (str[i] == '\n') || (str[i] == '\v') || (str[i] == '\f'))
		i++;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	num = 0;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		num = num * 10 + str[i++] - '0';
		if (num > (num * 10) || (num > 2147483647 && sign == 1)\
				|| (num > 2147483648 && sign == -1))
			error_output(stack);
	}
	if (str[i] || (i && (str[i - 1] == '-' || str[i - 1] == '+')))
		error_output(stack);
	return (num * sign);
}

static int	*create_a(t_stack *stack, char **av)
{
	int			*st_a;
	int			i;
	int			j;
	int			k;
	char		**arr;

	if (!(st_a = (int*)ft_memalloc(sizeof(int*) * stack->full_size)))
		exit(1);
	i = 0;
	k = 0;
	while (av[i])
	{
		arr = ft_strsplit(av[i], ' ');
		j = 0;
		while (arr[j])
		{
			st_a[k] = ps_atoi(stack, arr[j]);
			k++;
			j++;
		}
		i++;
		ps_free_arr(arr);
	}
	return (st_a);
}

static void	count_full_size(t_stack *stack, char **av)
{
	int		i;
	int		j;
	char	**arr;

	stack->full_size = 0;
	i = 0;
	while (av[i])
	{
		arr = ft_strsplit(av[i], ' ');
		j = 0;
		while (arr[j])
		{
			stack->full_size++;
			j++;
		}
		i++;
		ps_free_arr(arr);
	}
}

void		create_stacks(t_stack *stack, char **av)
{
	count_full_size(stack, av);
	stack->size_a = stack->full_size;
	stack->size_b = 0;
	stack->stack_a = create_a(stack, av);
	if (!(stack->stack_b = (int*)ft_memalloc(sizeof(int*) * stack->full_size)))
		exit(1);
	if (is_double(stack))
		error_output(stack);
}
