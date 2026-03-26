/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 07:32:19 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/26 09:46:00 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count(char ***big_str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (big_str[j])
	{
		i = 0;
		while (big_str[j][i])
		{
			k++;
			i++;
		}
		j++;
	}
	return (k);
}

static char	**create_table(int k, char ***big_str, int i, int j)
{
	char	**str;

	i = 0;
	j = 0;
	str = malloc(sizeof(char *) * (k + 1));
	if (!str)
		return (NULL);
	k = 0;
	while (big_str[j])
	{
		i = 0;
		while (big_str[j][i])
		{
			str[k] = ft_strdup(big_str[j][i]);
			free(big_str[j][i]);
			k++;
			i++;
		}
		free(big_str[j]);
		j++;
	}
	str[k] = NULL;
	free(big_str);
	return (str);
}

char	**argument_table(int argc, char **argv)
{
	char	***big_str;
	char	**str;
	int		k;
	int		i;
	int		j;

	i = 1;
	j = 0;
	k = 0;
	big_str = malloc(sizeof(char **) * argc);
	if (!big_str)
		return (NULL);
	while (i < argc)
	{
		big_str[j] = ft_split(argv[i], ' ');
		i++;
		j++;
	}
	big_str[j] = NULL;
	k = count(big_str);
	str = create_table(k, big_str, i, j);
	return (str);
}
