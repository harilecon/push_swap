/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:36:00 by tsitoand          #+#    #+#             */
/*   Updated: 2026/02/06 20:25:58 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	i;
	int	value;
	int	s;

	i = 0;
	s = 1;
	value = 0;
	while ((nptr[i] == ' ') || ((nptr[i] >= 9) && (nptr[i] <= 13)))
	{
		i++;
	}
	if ((nptr[i] == '-') || (nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			s = -1;
		i++;
	}
	while ((nptr[i] >= '0') && (nptr[i] <= '9'))
	{
		value = value * 10 + nptr[i] - '0';
		i++;
	}
	return (value * s);
}
