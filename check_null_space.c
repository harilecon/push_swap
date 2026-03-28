/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_null_space.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 08:56:06 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/28 09:13:53 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_null(char *str)
{
	int len;

	if (!str)
		return (-1);

	len = ft_strlen(str);
	if (len == 0)
		return (1);
	return (0);
}

static int	check_space(char *str)
{
	int i;
	int len;

	if (!str)
		return (-1);

	i = 0;
	len = ft_strlen(str);
	while (str[i] == ' ')
		i++;
	if ((len != 0) && (str[i] == '\0'))
		return (1);
	return (0);
}

char	**check_space_null(int	argc , char **argv)
{
	int i;

	if (!argv)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		if (check_null(argv[i]) > 0 || check_space(argv[i]) > 0)
			return (NULL);
		i++;
	}
	return(argv);
}
