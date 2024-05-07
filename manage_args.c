#include "push_swap.h"

void	check_validity(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if ((argv[i][j] < '0' || argv[i][j] > '9') && 
				(argv[i][j] != ' ' && argv[i][j] != '-'))
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			j++;
		}
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