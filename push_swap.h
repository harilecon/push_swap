/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 09:30:55 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/25 05:26:43 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(PUSH_SWAP_H)
# define PUSH_SWAP_H

# include <stdlib.h>
# include "ft_printf.h"
# include "libft/libft.h"

typedef struct s_liste
{
	unsigned int	index;
	long			value;
	int				sa;
	int				sb;
	struct s_liste	*next;
	struct s_liste	*previous;
}				t_liste;

typedef struct s_bunch
{
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

char			**argument(int argc, char **argv);
t_liste			*create_liste(long i);
long			greatest(t_liste	*stack);
long			char_lo(char *str);
int				check_order(t_liste *stack);
int				high_index(t_liste	*liste);
int				power(long nb);
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
void			add_back(t_liste **lst, t_liste *new_value);
// void			ft_printf_stack_index(t_liste	*tmp, char *str);
void			insertion(t_liste **stack, t_bunch **bunch_mark);
void			buble(t_liste	**stac, t_bunch **bunch_mark);
void			indexation(t_liste **stack);
void			radix(t_liste **stack, t_bunch **bunch_mark);
void			range(t_liste **stack, t_bunch **bunch_mark);

#endif // PUSH_SWAP_H
