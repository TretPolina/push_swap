/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <fford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 20:12:40 by fford             #+#    #+#             */
/*   Updated: 2020/08/29 21:00:14 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static int	check_solve(t_stack *stack)
{
	int	prev;
	int	i;

	i = 0;
	if (stack->size_b)
		return (0);
	while (stack->size_a--)
	{
		if (i != 0)
		{
			if (stack->stack_a[i] < prev)
				return (0);
		}
		prev = stack->stack_a[i];
		i++;
	}
	return (1);
}

static void	do_cm(t_stack *stack, char *line)
{
	if (ft_strequ(line, "sa"))
		cm_sa(stack);
	else if (ft_strequ(line, "sb"))
		cm_sb(stack);
	else if (ft_strequ(line, "pa"))
		cm_pa(stack);
	else if (ft_strequ(line, "pb"))
		cm_pb(stack);
	else if (ft_strequ(line, "ra"))
		cm_ra(stack);
	else if (ft_strequ(line, "rb"))
		cm_rb(stack);
	else if (ft_strequ(line, "rra"))
		cm_rra(stack);
	else if (ft_strequ(line, "rrb"))
		cm_rrb(stack);
	else if (ft_strequ(line, "ss"))
		cm_ss(stack);
	else if (ft_strequ(line, "rr"))
		cm_rr(stack);
	else if (ft_strequ(line, "rrr"))
		cm_rrr(stack);
	else
		error_output(stack);
}

static int	check_cm(t_stack *stack, int fd)
{
	char	*line;

	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (stack->flag_v)
			stack->flag_c ? ft_printf(MAG"Last operation %s\n"RESET, line)
			: ft_printf("Last operation %s\n", line);
		do_cm(stack, line);
		free(line);
		if (stack->flag_v)
			ft_print_stacks(stack);
	}
	if (check_solve(stack))
		return (1);
	return (0);
}

int			main(int ac, char **av)
{
	t_stack	stacks;
	int		fd;

	av++;
	ft_bzero(&stacks, sizeof(t_stack));
	ft_pars_flags(&av, &stacks);
	if (ac == 1)
		exit(0);
	fd = open(av[0], O_RDONLY);
	if (fd == -1)
		fd = 0;
	else
		av++;
	create_stacks(&stacks, av);
	if (check_cm(&stacks, fd))
		stacks.flag_c ? ft_printf(GRN"OK\n"RESET) : ft_printf("OK\n");
	else
		stacks.flag_c ? ft_printf(RED"KO\n"RESET) : ft_printf("KO\n");
	ps_free_st(&stacks);
	exit(0);
}
