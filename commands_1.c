/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_1                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <fford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 15:56:26 by fford             #+#    #+#             */
/*   Updated: 2020/08/21 16:20:04 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void		ps_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void		cm_sa(t_stack *stack)
{
	if (stack->size_a > 1)
		ps_swap(&stack->stack_a[0], &stack->stack_a[1]);
}

void		cm_sb(t_stack *stack)
{
	if (stack->size_b > 1)
		ps_swap(&stack->stack_b[0], &stack->stack_b[1]);
}

void		cm_pa(t_stack *stack)
{
	int	i;

	if (!stack->size_b)
		return ;
	i = stack->size_a;
	while (i != 0)
	{
		stack->stack_a[i] = stack->stack_a[i - 1];
		i--;
	}
	stack->stack_a[0] = stack->stack_b[0];
	stack->size_a++;
	i = 0;
	while (i != stack->size_b - 1)
	{
		stack->stack_b[i] = stack->stack_b[i + 1];
		i++;
	}
	stack->size_b--;
}

void		cm_pb(t_stack *stack)
{
	int	i;

	if (!stack->size_a)
		return ;
	i = stack->size_b;
	while (i != 0)
	{
		stack->stack_b[i] = stack->stack_b[i - 1];
		i--;
	}
	stack->stack_b[0] = stack->stack_a[0];
	stack->size_b++;
	i = 0;
	while (i != stack->size_a - 1)
	{
		stack->stack_a[i] = stack->stack_a[i + 1];
		i++;
	}
	stack->size_a--;
}
