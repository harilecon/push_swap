/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haranivo <haranivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 05:29:49 by haranivo          #+#    #+#             */
/*   Updated: 2026/03/25 14:10:52 by haranivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*is_flag(char *str)
{
	if (!str)
		return (0);
	if (ft_strcmp(str, "--simple"))
		return ("insertion");
	if (ft_strcmp(str, "--medium"))
		return ("range");
	if (ft_strcmp(str, "--complexe"))
		return ("radix");
	return (NULL);
}

int	where_flag(int argc, char **argv)
{
	int		count;
	char	**str;

	count = 1;
	if (!*argv)
		return (0);
	str = argument(argc, argv);
	while (str[count])
	{
		if (is_flag(str[count]))
			return (count);
		count++;
	}
	free_tab(str);
	return (0);
}

void	get_flag(int argc, char **argv)
{
	char	**str;
	char	*flag;
	int		i;

	i = where_flag(argc, argv);
	str = argument(argc, argv);
	flag = is_flag(str[i]);
	if (ft_strcmp(flag, "insertion"))
		printf("incertion\n"); // insertion();
	else if (ft_strcmp(flag, "range"))
		printf("range\n"); // range();
	else if (ft_strcmp(flag, "radix"))
		printf("radix\n"); // radix();
	i++;
	free_tab(str);
}
