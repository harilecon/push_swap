/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_push_swap.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 08:03:36 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/03 09:19:09 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef LIBFT_PUSH_SWAP_H
#define LIBFT_PUSH_SWAP_H

#include <stdlib.h>

typedef struct t_stack
{
	int		size;
	long	*value;
}				s_stack;


long	ft_strlo(char *s);
s_stack	*ft_free_stack(s_stack *stack);
s_stack	*create_stack(int argc, char **argv);

#endif
