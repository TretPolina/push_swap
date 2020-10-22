/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_3                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <fford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 15:32:20 by fford             #+#    #+#             */
/*   Updated: 2020/08/31 15:42:00 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	cm_ss(t_stack *stack)
{
	if (stack->size_a != 0 && stack->size_b != 0)
	{
		cm_sa(stack);
		cm_sb(stack);
	}
}

void	cm_rr(t_stack *stack)
{
	if (stack->size_a != 0 && stack->size_b != 0)
	{
		cm_ra(stack);
		cm_rb(stack);
	}
}

void	cm_rrr(t_stack *stack)
{
	if (stack->size_a != 0 && stack->size_b != 0)
	{
		cm_rra(stack);
		cm_rrb(stack);
	}
}
