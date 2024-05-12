/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-azz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 07:43:12 by isel-azz          #+#    #+#             */
/*   Updated: 2024/05/11 07:43:14 by isel-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**get_numbers(char **argv, int argc)
{
	static char	*numbers;
	static char	**matrix;
	int			i;

	i = 1;
	numbers = NULL;
	matrix = NULL;
	while (i < argc)
		numbers = ft_strjoin(numbers, argv[i++]);
	if (!numbers)
		return (NULL);
	matrix = ft_split(numbers, ' ');
	free(numbers);
	if (!matrix)
		return (NULL);
	return (matrix);
}

int	main(int argc, char **argv)
{
	t_stack_needs	*a;
	t_stack_needs	*b;

	a = NULL;
	b = NULL;
	if (argc > 1)
	{
		check_validity(argv, argc);
		argv = get_numbers(argv, argc);
		check_numbers(argv);
		create_stack(argv, &a);
		if (is_sorted(a) == 0)
		{
			if (stack_len(a) <= 3)
				sort_three(&a);
			else
				push_swap_magic(&a, &b);
		}
		freelist(a);
	}
	return (0);
}
