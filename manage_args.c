/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-azz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 07:43:40 by isel-azz          #+#    #+#             */
/*   Updated: 2024/05/11 07:43:43 by isel-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_validity(char **argv, int argc)
{
	int	i;
	int	j;
	int	numbers_count;

	i = 1;
	while (i < argc)
	{
		j = 0;
		numbers_count = 0;
		while (argv[i][j] != '\0')
		{
			if ((argv[i][j] < '0' || argv[i][j] > '9') && 
				(argv[i][j] != ' ' && argv[i][j] != '-' && argv[i][j] != '+'))
				Error();
			if (test_case(argv, i, j) == 1)
				Error();
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
				numbers_count++;
			j++;
		}
		if (numbers_count == 0)
			Error();
		i++;
	}
}

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

void	check_duplicates(char **numbers)
{
	int	i;
	int	j;

	i = 0;
	while (numbers[i] != NULL)
	{
		j = 0;
		while (numbers[j] != NULL)
		{
			if (ft_strcmp(numbers[i], numbers[j]) == 0 && i != j)
				free_numbers(numbers, 1);
			j++;
		}
		i++;
	}
}

void	check_numbers(char **numbers)
{
	int	i;
	int	j;

	i = 0;
	while (numbers[i] != NULL)
	{
		j = 0;
		while (numbers[i][j] != '\0')
		{
			if (numbers[i][j] == '-' && j != 0)
				free_numbers(numbers, 1);
			j++;
		}
		i++;
	}
	j = 0;
	while (j < i)
		ft_atoi(numbers[j++], numbers);
	check_duplicates(numbers);
}
