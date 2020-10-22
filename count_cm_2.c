/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_cm_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <fford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 16:49:58 by fford             #+#    #+#             */
/*   Updated: 2020/09/12 18:56:02 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static int	find_min_i(t_stack *stack)
{
	int inda;
	int min_i;

	min_i = 0;
	inda = 0;
	while (inda++ < stack->size_a)
		if (stack->stack_a[min_i] > stack->stack_a[inda])
			min_i = inda;
	return (min_i);
}

static int	find_max_i(t_stack *stack)
{
	int inda;
	int max_i;

	max_i = 0;
	inda = 0;
	while (inda++ < stack->size_a)
		if (stack->stack_a[max_i] < stack->stack_a[inda])
			max_i = inda;
	return (max_i);
}

int			find_inda(t_stack *stack, int val, int inda)
{
	int min_i;
	int max_i;

	min_i = find_min_i(stack);
	max_i = find_max_i(stack);
	if (val < stack->stack_a[min_i])
		return (min_i);
	if (val > stack->stack_a[max_i])
	{
		if (max_i == stack->size_a - 1)
			return (0);
		else
			return (max_i + 1);
	}
	inda = 0;
	while (inda < stack->size_a)
	{
		if (val > stack->stack_a[inda] && val < stack->stack_a[inda + 1])
			return (inda + 1);
		if (val < stack->stack_a[inda] && val > stack->stack_a[inda + 1] &&
			inda != max_i)
			return (inda + 2);
		inda++;
	}
	return (0);
}

int			count_all(t_cm *counter)
{
	int all_car;

	all_car = counter->ra + counter->rb + counter->rr +
			counter->rra + counter->rrb + counter->rrr;
	if (all_car < counter->all_cm)
	{
		counter->all_cm = all_car;
		return (1);
	}
	return (0);
}
