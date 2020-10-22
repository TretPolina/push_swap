/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_func                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <fford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 17:28:10 by fford             #+#    #+#             */
/*   Updated: 2020/08/25 18:00:14 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	error_output(t_stack *stack)
{
	stack->flag_c ? ft_printf(RED"Error\n"RESET) : ft_printf("Error\n");
	exit(0);
}

void	ps_free_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		ft_strdel(&arr[i++]);
	free(arr);
}

void	ps_free_st(t_stack *stack)
{
	free(stack->stack_a);
	free(stack->stack_b);
}

void	ps_free_seq(t_sort *seq)
{
	free(seq->count_elem);
	free(seq->sort_nbrs);
}
