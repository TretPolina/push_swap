/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <fford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 15:56:26 by fford             #+#    #+#             */
/*   Updated: 2020/08/21 16:20:04 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/includes/ft_printf.h"
# include "../ft_printf/libft/libft.h"
# include <fcntl.h>

# define CYN	"\x1B[36m"
# define RED	"\x1B[31m"
# define GRN	"\x1B[32m"
# define YEL	"\x1B[33m"
# define BLU	"\x1B[34m"
# define MAG	"\x1B[35m"
# define WHT	"\x1B[37m"
# define RESET	"\x1B[0m"

typedef struct	s_stack
{
	int			*stack_a;
	int			*stack_b;
	int			size_a;
	int			size_b;
	int			full_size;
	int			flag_v;
	int			flag_c;
}				t_stack;

typedef struct	s_sort
{
	int			*count_elem;
	int			*sort_nbrs;
	int			ind_max;
}				t_sort;

typedef struct	s_cm
{
	int			ind;
	int			ra;
	int			rra;
	int			rb;
	int			rrb;
	int			rr;
	int			rrr;
	int			all_cm;
}				t_cm;

void			cm_sa(t_stack *stack);
void			cm_sb(t_stack *stack);
void			cm_pa(t_stack *stack);
void			cm_pb(t_stack *stack);
void			cm_ra(t_stack *stack);
void			cm_rb(t_stack *stack);
void			cm_rra(t_stack *stack);
void			cm_rrb(t_stack *stack);
void			cm_ss(t_stack *stack);
void			cm_rr(t_stack *stack);
void			cm_rrr(t_stack *stack);

void			ft_pars_flags(char ***av, t_stack *stack);
void			ft_print_stacks(t_stack *stack);

void			ps_swap(int *a, int *b);
void			error_output(t_stack *stack);
void			create_stacks(t_stack *stack, char **av);
void			ps_free_arr(char **arr);
void			ps_free_st(t_stack *stack);
void			ps_free_seq(t_sort *seq);

int				max_sort_seq(t_stack *stack, t_sort *seq);
void			fill_count_elem(t_stack *stack, t_sort *seq, int ind, int i);
int				fill_ind_max(t_stack *stack, t_sort *seq);
void			fill_sort_nbrs(t_stack *stack, t_sort *seq);

void			move_to_b(t_stack *stack, t_sort *seq);
void			ps_counter(t_stack *stack, t_cm *counter);
int				count_all(t_cm *counter);
int				find_inda(t_stack *stack, int val, int inda);

#endif
