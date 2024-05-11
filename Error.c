#include "push_swap.h"

void	Error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	test_case(char **argv, int i, int j)
{
	if ((argv[i][j] == '-' && argv[i][j + 1] == '-')
		||(argv[i][j] == '-' && argv[i][j + 1] == '+')
		|| (argv[i][j] == '+' && argv[i][j + 1] == '+')
		|| (argv[i][j] == '+' && argv[i][j + 1] == '-'))
			return (1);
	return (0);
}