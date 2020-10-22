/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <fford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 19:01:32 by fford             #+#    #+#             */
/*   Updated: 2020/09/01 21:00:14 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static void	ps_do_cm_next(t_stack *stack, t_cm *counter)
{
	int i;

	i = 0;
	while (i++ < counter->rrb)
	{
		stack->flag_c ? ft_printf(CYN"rrb\n"RESET) : ft_printf("rrb\n");
		cm_rrb(stack);
	}
	i = 0;
	while (i++ < counter->rr)
	{
		stack->flag_c ? ft_printf(CYN"rr\n"RESET) : ft_printf("rr\n");
		cm_rr(stack);
	}
	i = 0;
	while (i++ < counter->rrr)
	{
		stack->flag_c ? ft_printf(CYN"rrr\n"RESET) : ft_printf("rrr\n");
		cm_rrr(stack);
	}
	stack->flag_c ? ft_printf(CYN"pa\n"RESET) : ft_printf("pa\n");
	cm_pa(stack);
}

static void	ps_do_cm(t_stack *stack, t_cm *counter)
{
	int i;

	i = 0;
	while (i++ < counter->ra)
	{
		stack->flag_c ? ft_printf(CYN"ra\n"RESET) : ft_printf("ra\n");
		cm_ra(stack);
	}
	i = 0;
	while (i++ < counter->rb)
	{
		stack->flag_c ? ft_printf(CYN"rb\n"RESET) : ft_printf("rb\n");
		cm_rb(stack);
	}
	i = 0;
	while (i++ < counter->rra)
	{
		stack->flag_c ? ft_printf(CYN"rra\n"RESET) : ft_printf("rra\n");
		cm_rra(stack);
	}
	ps_do_cm_next(stack, counter);
}

static void	asc_order_next(t_stack *stack, int min, int min_i)
{
	while (stack->stack_a[0] != min)
	{
		if (min_i)
		{
			stack->flag_c ? ft_printf(CYN"ra\n"RESET) : ft_printf("ra\n");
			cm_ra(stack);
		}
		else
		{
			stack->flag_c ? ft_printf(CYN"rra\n"RESET) : ft_printf("rra\n");
			cm_rra(stack);
		}
	}
}

static void	asc_order(t_stack *stack)
{
	int i;
	int min;
	int min_i;

	i = 0;
	min = stack->stack_a[0];
	while (i < stack->size_a)
	{
		if (min > stack->stack_a[i])
		{
			min = stack->stack_a[i];
			min_i = i;
		}
		i++;
	}
	if (min_i <= stack->size_a / 2)
		min_i = 1;
	else
		min_i = 0;
	asc_order_next(stack, min, min_i);
}

int			main(int ac, char **av)
{
	t_stack	stacks;
	t_sort	seq;
	t_cm	counter;
	int		b;

	av++;
	ft_bzero(&stacks, sizeof(t_stack));
	ft_pars_flags(&av, &stacks);
	if (ac == 1)
		exit(0);
	create_stacks(&stacks, av);
	if (max_sort_seq(&stacks, &seq) != 1)
	{
		move_to_b(&stacks, &seq);
		ps_free_seq(&seq);
	}
	b = stacks.size_b;
	while (b-- > 0)
	{
		ps_counter(&stacks, &counter);
		ps_do_cm(&stacks, &counter);
	}
	asc_order(&stacks);
	ps_free_st(&stacks);
	exit(0);
}
