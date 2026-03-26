/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 09:30:55 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/26 12:49:55 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(PUSH_SWAP_H)
# define PUSH_SWAP_H

# include <stdlib.h>
# include "ft_printf.h"
# include "ft_printf_error.h"
# include "libft/libft.h"

typedef struct s_liste
{
	unsigned int	index;
	long			value;
	struct s_liste	*next;
	struct s_liste	*previous;
}				t_liste;

typedef struct s_bunch
{
	char	*complexity;
	char	*strategy;
	int	sa;
	int	sb;
	int	ss;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	pa;
	int	pb;
}				t_bunch;

typedef struct s_argument
{
	char	**argument;
	char	**number;
}			t_argument;

char			**argument_table(int argc, char **argv);
void			which_algo(char **str, t_liste **stack, t_bunch **bunch_mark);
double			compute_disorder(t_liste *stack);
long			greatest(t_liste	*stack);
long			char_lo(char *str);
t_argument		*struct_argument(char **str);
t_liste			*create_liste(long i);
int				check_order(t_liste *stack);
int				high_index(t_liste	*liste);
int				power(long nb);
int				ft_strcmp(char *s1, char *s2);
unsigned int	low_index(t_liste *liste);
unsigned int	max_bits(t_liste *stack);
unsigned int	stack_size(t_liste	*liste);
void			sa(t_liste **a, t_bunch **bunch_mark);
void			sb(t_liste **b, t_bunch **bunch_mark);
void			ss(t_liste **a, t_liste **b, t_bunch **bunch_mark);
void			ra(t_liste **a, t_bunch **bunch_mark);
void			rb(t_liste **b, t_bunch **bunch_mark);
void			rra(t_liste **a, t_bunch **bunch_mark);
void			rrb(t_liste **b, t_bunch **bunch_mark);
void			rrr(t_liste **a, t_liste **b, t_bunch **bunch_mark);
void			pa(t_liste **a, t_liste **b, t_bunch **bunch_mark);
void			pb(t_liste **a, t_liste **b, t_bunch **bunch_mark);
void			free_tab(char **str);
void			free_stack(t_liste	**stack);
void			free_argument(t_argument **argument);
void			add_back(t_liste **lst, t_liste *new_value);
void			insertion(t_liste **stack, t_bunch **bunch_mark);
void			bubble(t_liste	**stac, t_bunch **bunch_mark);
void			indexation(t_liste **stack);
void			radix(t_liste **stack, t_bunch **bunch_mark);
void			range(t_liste **stack, t_bunch **bunch_mark);
void	bunch(double disorder, t_bunch	*bunch_mark);
void			initialisation_bunch_value(t_bunch **bunch_mark);
void			choose_your_destiny(t_liste	**stack, t_bunch **bunch_mark);

#endif // PUSH_SWAP_H
