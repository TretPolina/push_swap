/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <fford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 16:12:10 by fford             #+#    #+#             */
/*   Updated: 2020/09/13 18:00:14 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void		ft_pars_flags(char ***av, t_stack *stack)
{
	if (ft_strequ(**av, "-v"))
	{
		stack->flag_v = 1;
		(*av)++;
		ft_pars_flags(av, stack);
	}
	if (ft_strequ(**av, "-c"))
	{
		stack->flag_c = 1;
		(*av)++;
		ft_pars_flags(av, stack);
	}
}

static void	print_stack_b(t_stack *stack)
{
	int i;

	stack->flag_c ? ft_printf(BLU"STACK B %d elem - "RESET, stack->size_b) :
	ft_printf("STACK B %d elem - ", stack->size_b);
	if (!stack->size_b)
		stack->flag_c ? ft_printf(BLU"empty"RESET) :
		ft_printf("empty");
	else
	{
		i = 0;
		while (i < stack->size_b)
		{
			stack->flag_c ? ft_printf(BLU"%d "RESET, stack->stack_b[i]) :
			ft_printf("%d ", stack->stack_b[i]);
			i++;
		}
	}
	ft_printf("\n");
}

void		ft_print_stacks(t_stack *stack)
{
	int i;

	stack->flag_c ? ft_printf(YEL"STACK A %d elem - "RESET, stack->size_a) :
	ft_printf("STACK A %d elem - ", stack->size_a);
	if (!stack->size_a)
		stack->flag_c ? ft_printf(YEL"empty"RESET) : ft_printf("empty");
	else
	{
		i = 0;
		while (i < stack->size_a)
		{
			stack->flag_c ? ft_printf(YEL"%d "RESET, stack->stack_a[i]) :
			ft_printf("%d ", stack->stack_a[i]);
			i++;
		}
	}
	ft_printf("\n");
	print_stack_b(stack);
}
