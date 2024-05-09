#include "push_swap.h"

void	insert(t_stack_needs *a, t_stack_needs *b)
{

}

void	start_nodes(t_stack_needs *a, t_stack_needs *b)
{
	set_positions(a);
	set_positions(b);
	set_targets(a, b);
	set_push_cost(a, b);
	set_priority(b);
}

void	push_swap_magic(t_stack_needs **a, t_stack_needs **b)
{
	t_stack_needs	*smallest;
	int				a_len;

	a_len = stack_len(*a);
	while (a_len-- > 3)
		push_b(a, b);
	sort_three(a,b);
	while (*b)
	{
		start_nodes(*a, *b);
		insert(a, b);
	}
	set_positions(*a);
	smallest = get_smallest(*a);
	if (smallest->upper_half)
		while (*a != smallest)
			rotate_a(a);
	else
		while (*a != smallest)
			reverse_rotate_a(a);
}