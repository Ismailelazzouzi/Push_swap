#include "push_swap.h"

void	sort_three(t_stack_needs **a, t_stack_needs **b)
{
	t_stack_needs *biggest;

	biggest = find_highest(*a);
	if (stack_len(*a) == 2)
		sa(a);
	else
	{
		if (biggest == (*a))
			rotate_a(a);
		else if (biggest == (*a)->next)
			reverse_rotate_a(a);
		if ((*a)->value > (*a)->next->value)
			sa(a);
	}
}