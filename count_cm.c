/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_cm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <fford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 17:55:58 by fford             #+#    #+#             */
/*   Updated: 2020/09/05 17:56:02 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static void	count_a(t_stack *stack, t_cm *counter, int ind)
{
	counter->rra = 0;
	counter->ra = 0;
	if (ind <= stack->size_a / 2)
		counter->ra = ind;
	else
		counter->rra = stack->size_a - ind;
}

static void	count_b(t_stack *stack, t_cm *counter, int ind)
{
	counter->rrb = 0;
	counter->rb = 0;
	if (ind <= stack->size_b / 2)
		counter->rb = ind;
	else
		counter->rrb = stack->size_b - ind;
}

static void	opt_rr(t_cm *counter)
{
	counter->rr = 0;
	if (counter->ra > 0 && counter->rb > 0)
	{
		if (counter->ra >= counter->rb)
		{
			counter->rr = counter->rb;
			counter->ra -= counter->rb;
			counter->rb = 0;
		}
		if (counter->ra < counter->rb)
		{
			counter->rr = counter->ra;
			counter->rb -= counter->ra;
			counter->ra = 0;
		}
	}
}

static void	opt_rrr(t_cm *counter)
{
	counter->rrr = 0;
	if (counter->rra > 0 && counter->rrb > 0)
	{
		if (counter->rra >= counter->rrb)
		{
			counter->rrr = counter->rrb;
			counter->rra -= counter->rrb;
			counter->rrb = 0;
		}
		if (counter->rra < counter->rrb)
		{
			counter->rrr = counter->rra;
			counter->rrb -= counter->rra;
			counter->rra = 0;
		}
	}
}

void		ps_counter(t_stack *stack, t_cm *counter)
{
	int b;
	int a;

	ft_bzero(counter, sizeof(t_cm));
	counter->all_cm = 99999;
	b = 0;
	counter->ind = b;
	while (b < stack->size_b)
	{
		a = find_inda(stack, stack->stack_b[b], 0);
		count_a(stack, counter, a);
		count_b(stack, counter, b);
		opt_rr(counter);
		opt_rrr(counter);
		if (count_all(counter))
			counter->ind = b;
		b++;
	}
	count_a(stack, counter, find_inda(stack, stack->stack_b[counter->ind], 0));
	count_b(stack, counter, counter->ind);
	opt_rr(counter);
	opt_rrr(counter);
}
