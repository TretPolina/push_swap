/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_sort_seq                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <fford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 19:25:32 by fford             #+#    #+#             */
/*   Updated: 2020/09/03 22:00:14 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static void	sort_arr(t_stack *stack, t_sort *seq)
{
	int	len_sort;

	len_sort = seq->count_elem[seq->ind_max] + 1;
	if (!(seq->sort_nbrs = (int*)ft_memalloc(sizeof(int*) * len_sort)))
		exit(1);
	fill_sort_nbrs(stack, seq);
}

static void	ps_bzero(int *arr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		arr[i++] = 0;
}

static void	sort_three_decr(t_stack *stack)
{
	stack->flag_c ? ft_printf(CYN"sa\n"RESET) : ft_printf("sa\n");
	cm_sa(stack);
	stack->flag_c ? ft_printf(CYN"rra\n"RESET) : ft_printf("rra\n");
	cm_rra(stack);
}

static void	sort_decrease(t_stack *stack)
{
	if (stack->size_a > 3)
	{
		while (stack->size_a != 3)
		{
			stack->flag_c ? ft_printf(CYN"pb\n"RESET) : ft_printf("pb\n");
			cm_pb(stack);
		}
	}
	if (stack->size_a == 3)
		sort_three_decr(stack);
}

int			max_sort_seq(t_stack *stack, t_sort *seq)
{
	seq->ind_max = 0;
	if (!(seq->count_elem = (int*)ft_memalloc(sizeof(int*) * stack->full_size)))
		exit(1);
	ps_bzero(seq->count_elem, stack->full_size);
	fill_count_elem(stack, seq, 0, 0);
	if (fill_ind_max(stack, seq) == 1)
		return (1);
	if (seq->count_elem[seq->ind_max] == 1)
	{
		sort_decrease(stack);
		return (1);
	}
	else
		sort_arr(stack, seq);
	return (0);
}
