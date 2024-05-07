#include "push_swap.h"

void	reverse_rotate(t_stack_needs **stack)
{
	t_stack_needs *last_node;

	if (stack == NULL || *stack == NULL || stack_len(*stack) <= 1)
		return ;
	last_node = get_last_node(*stack);
	(*stack)->prev = last_node;
	last_node->next = *stack;
	*stack = (*stack)->prev;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

void	reverse_rotate_a(t_stack_needs **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack_needs **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	reverse_rotate_a_b(t_stack_needs **a, t_stack_needs **b)
{
	reverse_rotate_a(a);
	reverse_rotate_b(b);
	write(1, "rrr\n", 4);
}