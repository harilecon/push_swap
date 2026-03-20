/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@tsitoand@student.42a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 09:30:55 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/20 07:27:54 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(PUSH_SWAP_H)
#define PUSH_SWAP_H

#include <stdlib.h>

typedef struct	s_liste
{
	int		index;
	long	value;
	struct s_liste	*next;
	struct s_liste	*previous;
}		t_liste;

void	sa(t_liste **a);
void	sb(t_liste **b);
void	ss(t_liste **a, t_liste **b);
void	ra(t_liste **a);
void	rb(t_liste **b);
void	rra(t_liste **a);
void	rrb(t_liste **b);
void	rrr(t_liste **a, t_liste **b);
void	pa(t_liste **a, t_liste **b);
void	pb(t_liste **a, t_liste **b);
void	add_back(t_liste **lst, t_liste *new_value);
int		high_index(t_liste	*liste);
int		stack_size(t_liste	*liste);
long	char_lo(char *str);
t_liste	*create_liste(long i);

void	printf_stack_index(t_liste	*tmp, char *str);

long	greatest(t_liste	*stack);
void insertion(t_liste **stack);

int	power(long nb);
void	printf_stack(t_liste	*tmp, char *str);
int	low_index(t_liste	*liste);
void	buble(t_liste	**stack);
int	max_bits(t_liste *stack);
void	indexation(t_liste **stack);
void radix(t_liste **stack);

#endif // PUSH_SWAP_H
