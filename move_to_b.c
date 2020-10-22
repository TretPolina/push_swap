/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_b                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <fford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 14:20:00 by fford             #+#    #+#             */
/*   Updated: 2020/09/04 16:50:14 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static int		nbr_is_sort(t_sort *seq, int nbr)
{
	int len_sort;
	int	i;

	len_sort = seq->count_elem[seq->ind_max] + 1;
	i = 0;
	while (i < len_sort)
	{
		if (nbr == seq->sort_nbrs[i])
			return (1);
		i++;
	}
	return (0);
}

static void		mv_nbr(t_stack *stack, t_sort *seq)
{
	if (!(nbr_is_sort(seq, stack->stack_a[0])))
	{
		stack->flag_c ? ft_printf(CYN"pb\n"RESET) : ft_printf("pb\n");
		cm_pb(stack);
	}
	else if (nbr_is_sort(seq, stack->stack_a[0]))
	{
		stack->flag_c ? ft_printf(CYN"ra\n"RESET) : ft_printf("ra\n");
		cm_ra(stack);
	}
}

void			move_to_b(t_stack *stack, t_sort *seq)
{
	int last_a;

	last_a = stack->stack_a[stack->full_size - 1];
	while (stack->stack_a[0] != last_a)
		mv_nbr(stack, seq);
	mv_nbr(stack, seq);
}
