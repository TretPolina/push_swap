/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_2                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <fford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 20:51:26 by fford             #+#    #+#             */
/*   Updated: 2020/08/21 21:02:04 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	cm_ra(t_stack *stack)
{
	int tmp;
	int i;

	if (stack->size_a > 1)
	{
		tmp = stack->stack_a[0];
		i = 0;
		while (i != stack->size_a - 1)
		{
			stack->stack_a[i] = stack->stack_a[i + 1];
			i++;
		}
		stack->stack_a[stack->size_a - 1] = tmp;
	}
}

void	cm_rb(t_stack *stack)
{
	int tmp;
	int i;

	if (stack->size_b > 1)
	{
		tmp = stack->stack_b[0];
		i = 0;
		while (i != stack->size_b - 1)
		{
			stack->stack_b[i] = stack->stack_b[i + 1];
			i++;
		}
		stack->stack_b[stack->size_b - 1] = tmp;
	}
}

void	cm_rra(t_stack *stack)
{
	int tmp;
	int i;

	if (stack->size_a > 1)
	{
		tmp = stack->stack_a[stack->size_a - 1];
		i = stack->size_a - 1;
		while (i != 0)
		{
			stack->stack_a[i] = stack->stack_a[i - 1];
			i--;
		}
		stack->stack_a[0] = tmp;
	}
}

void	cm_rrb(t_stack *stack)
{
	int tmp;
	int i;

	if (stack->size_b > 1)
	{
		tmp = stack->stack_b[stack->size_b - 1];
		i = stack->size_b - 1;
		while (i != 0)
		{
			stack->stack_b[i] = stack->stack_b[i - 1];
			i--;
		}
		stack->stack_b[0] = tmp;
	}
}
