/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_sort                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <fford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 20:16:06 by fford             #+#    #+#             */
/*   Updated: 2020/09/03 22:00:14 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	fill_count_elem(t_stack *stack, t_sort *seq, int ind, int i)
{
	int	j;

	while (ind < stack->full_size)
	{
		i = ind;
		j = i;
		while (j < stack->full_size)
		{
			if (stack->stack_a[i] < stack->stack_a[j++])
			{
				seq->count_elem[ind]++;
				i = j - 1;
			}
		}
		j = 0;
		while (j < ind)
		{
			if (stack->stack_a[i] < stack->stack_a[j++])
			{
				seq->count_elem[ind]++;
				i = j - 1;
			}
		}
		ind++;
	}
}

int		fill_ind_max(t_stack *stack, t_sort *seq)
{
	int i;

	seq->ind_max = 0;
	i = 1;
	while (i < stack->full_size)
	{
		if (seq->count_elem[seq->ind_max] < seq->count_elem[i])
			seq->ind_max = i;
		i++;
	}
	if (seq->count_elem[seq->ind_max] == stack->full_size - 1)
		return (1);
	return (0);
}

void	fill_sort_nbrs(t_stack *stack, t_sort *seq)
{
	int i;
	int j;
	int s;

	i = seq->ind_max;
	seq->sort_nbrs[0] = stack->stack_a[i];
	s = 1;
	j = i + 1;
	while (j < stack->full_size)
		if (stack->stack_a[i] < stack->stack_a[j])
		{
			seq->sort_nbrs[s++] = stack->stack_a[j++];
			i = j - 1;
		}
		else
			j++;
	j = 0;
	while (j < seq->ind_max)
		if (stack->stack_a[i] < stack->stack_a[j])
		{
			seq->sort_nbrs[s++] = stack->stack_a[j++];
			i = j - 1;
		}
		else
			j++;
}
