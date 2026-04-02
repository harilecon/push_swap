/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_argument.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 10:17:06 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/31 14:18:12 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_argument(t_argument **argument)
{
	int	i;

	i = 0;
	if ((*argument)->argument)
	{
		while ((*argument)->argument[i])
		{
			free((*argument)->argument[i]);
			i++;
		}
	}
	free((*argument)->argument);
	i = 0;
	if ((*argument)->number)
	{
		while ((*argument)->number[i])
		{
			free((*argument)->number[i]);
			i++;
		}
	}
	free((*argument)->number);
	free(*argument);
}

static int	not_number(char *str)
{
	int	i;

	if (!str)
		return (1);
	i = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		i++;
		if (!str[i])
			return (1);
	}
	{
		while (str[i])
		{
			if (str[i] < '0' || str[i] > '9')
				return (1);
			i++;
		}
	}
	return (0);
}

char	**new_tab(char **old_tab, char *new_element)
{
	int		i;
	int		tab_size;
	char	**new_tab;

	if (!new_element)
		return (old_tab);
	tab_size = 0;
	i = 0;
	if (old_tab)
	{
		while (old_tab[tab_size])
			tab_size++;
	}
	new_tab = malloc(sizeof(char *) * (tab_size + 2));
	if (!new_tab)
		return (NULL);
	while (i < tab_size)
	{
		new_tab[i] = ft_strdup(old_tab[i]);
		free(old_tab[i]);
		i++;
	}
	new_tab[i] = ft_strdup(new_element);
	new_tab[i + 1] = NULL;
	return (free(old_tab), new_tab);
}

t_argument	**condition(char **str, int i, t_argument **argument)
{
	if (not_number(str[i]) == 0)
	{
		(*argument)->number = new_tab((*argument)->number, str[i]);
		if (!(*argument)->number)
		{
			free_argument(argument);
			return (NULL);
		}
	}
	else
	{
		(*argument)->argument = new_tab((*argument)->argument, str[i]);
		if (!(*argument)->argument)
		{
			free_argument(argument);
			return (NULL);
		}
	}
	return (argument);
}

t_argument	*struct_argument(char **str)
{
	int			i;
	t_argument	*argument;

	argument = malloc(sizeof(t_argument));
	if (!argument)
		return (NULL);
	i = 0;
	argument->argument = NULL;
	argument->number = NULL;
	while (str[i])
	{
		if (!(condition(str, i, &argument)))
			return (NULL);
		i++;
	}
	free_tab(str);
	return (argument);
}
