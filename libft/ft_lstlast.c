/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 09:38:12 by tsitoand          #+#    #+#             */
/*   Updated: 2026/02/05 14:12:47 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temporary;

	temporary = lst;
	if (!temporary)
		return (NULL);
	while (temporary->next)
	{
		temporary = temporary->next;
	}
	return (temporary);
}
