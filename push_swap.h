/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haranivo <haranivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 09:30:55 by tsitoand          #+#    #+#             */
/*   Updated: 2026/04/03 12:34:47 by haranivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf_fd.h"
# include "libft/libft.h"
# include <stdlib.h>

typedef struct s_data
{
	unsigned int	index;
	int				value;
	struct s_data	*next;
	struct s_data	*previous;
}					t_data;

typedef struct s_bench
{
	char			*complexity;
	char			*strategy;
	int				sa;
	int				sb;
	int				ss;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				pa;
	int				pb;
}					t_bench;

typedef struct s_argument
{
	char			**argument;
	char			**number;
}					t_argument;

char				**argument_table(int argc, char **argv);
char				**table_check_min_max(char **str);
char				**check_space_null(int argc, char **argv);
void				get_flag(char **str, t_data **stack, t_bench **bench_mark);
double				compute_disorder(t_data *stack);
int					char_to_int(char *str);
t_argument			*struct_argument(char **str);
t_data				*create_liste(int i);
int					high_index(t_data *liste);
int					ft_strcmp(char *s1, char *s2);
int					check_doublon(char **table);
unsigned int		low_index(t_data *liste);
unsigned int		stack_size(t_data *liste);
void				sa(t_data **a, t_bench **bench_mark);
void				sb(t_data **b, t_bench **bench_mark);
void				ss(t_data **a, t_data **b, t_bench **bench_mark);
void				ra(t_data **a, t_bench **bench_mark);
void				rb(t_data **b, t_bench **bench_mark);
void				rra(t_data **a, t_bench **bench_mark);
void				rrb(t_data **b, t_bench **bench_mark);
void				rrr(t_data **a, t_data **b, t_bench **bench_mark);
void				pa(t_data **a, t_data **b, t_bench **bench_mark);
void				pb(t_data **a, t_data **b, t_bench **bench_mark);
void				free_tab(char **str);
void				free_stack(t_data **stack);
void				free_argument(t_argument **argument);
void				add_back(t_data **lst, t_data *new_value);
void				insertion(t_data **stack, t_bench **bench_mark);
void				indexation(t_data **stack);
void				radix(t_data **stack, t_bench **bench_mark);
void				chunck(t_data **stack, t_bench **bench_mark);
void				bench(double disorder, t_bench *bench_mark);
void				three_elements(t_data **stack, t_bench **bench_mark,
						double disorder);
void				two_elements(t_data **stack, t_bench **bench_mark);
void				five_elements(t_data **stack, t_bench **bench_mark,
						double disorder);
void				initialisation_bench_value(t_bench **bench_mark);
void				choose_your_destiny(t_data **stack, t_bench **bench_mark);

#endif
