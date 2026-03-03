/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 07:41:11 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/03 08:33:50 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

long	ft_strlo(char *s)
{
	long	nb;
	int		i;

	nb = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if ((s[i] >= '0') && (s[i] <= '9'))
					nb = nb * 10 + s[i] - '0';
		else
			return (0);
		i++;
	}
	return (nb);
}
