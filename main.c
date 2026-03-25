/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:47:50 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/25 09:38:08 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	free_stack(t_liste	**stack)
{
	t_liste	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

void	free_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i])
		free(str[i]);
		i++;
	}
	free(str);
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

char	**argument(int argc, char **argv)
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
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	**str;
	t_liste	*stack;
	t_liste	*tmp;
	static t_bunch	*bunch_mark;
	int		i;

	stack = NULL;
	bunch_mark = malloc(sizeof(t_bunch));
	str = argument(argc, argv);
	i = 0;
	while (str[i])
	{
		tmp =  create_liste(char_lo(str[i]));
		add_back(&stack, tmp);
		i++;
	}

		initialisation_bunch_value(&bunch_mark);


	double disorder = compute_disorder(stack);

	if (disorder == 0)
	{
		free(bunch_mark);
		free_stack(&stack);
		free_tab(str);
		return (0);
	}
	else if (disorder > 0 && disorder < 0.2)
	{
		insertion(&stack, &bunch_mark);
		bunch_mark->complexity = "O(n^2)";
	}
	else if (disorder >= 0.2 && disorder <= 0.5)
	{
		range(&stack, &bunch_mark);
		bunch_mark->complexity = "O(n√n)";
	}
	else
	{
		radix(&stack, &bunch_mark);
		bunch_mark->complexity = "O(nlogn)";
	}
		// printf("high= %f\n", disorder);
	// printf("desordre = %f\n", test);
	// buble(&stack, &bunch_mark);
	// radix(&stack, &bunch_mark);
	// insertion (&stack, &bunch_mark);
	//  range(&stack, &bunch_mark);

	// printf("\n\nbuch\nsa=%d\npb=%d\npa=%d\n", bunch_mark->sa, bunch_mark->pa, bunch_mark->pa);

// 	printf("\n\nbunch\nsa=%d\nsb=%d\nss=%d\npa=%d\npb=%d\nra=%d\nrb=%d\nrr=%d\nrra=%d\nrrb=%d\nrrr=%d\n",
//     bunch_mark->sa,
//     bunch_mark->sb,
//     bunch_mark->ss,
//     bunch_mark->pa,
//     bunch_mark->pb,
//     bunch_mark->ra,
//     bunch_mark->rb,
//     bunch_mark->rr,
//     bunch_mark->rra,
//     bunch_mark->rrb,
//     bunch_mark->rrr
// );

	bunch(bunch_mark);
	free(bunch_mark);
	free_stack(&stack);
	free_tab(str);
}
