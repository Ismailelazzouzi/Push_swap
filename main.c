#include <stdio.h>
#include "push_swap.h"

void	leakcheck(void)
{
	system("leaks a.out");
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
		if (is_sorted(a) == 1)
			printf("stack a is sorted\n");
		else
		{
			if (stack_len(a) <= 3)
				sort_three(&a, &b);
		}
	}
	if (is_sorted(a) == 1)
		printf("stack a is sorted\n");
	return (0);
}

// int main(int argc, char **argv)
// {
// 	ft_main(argc, argv);
// 	leakcheck();
// }