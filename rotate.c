#include "push_swap.h"

void	rotate_stack(t_stack_needs **stack)
{
	t_stack_needs *last_node;

	if (stack == NULL || *stack == NULL || stack_len(*stack) <= 1)
		return ;
	last_node = get_last_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	rotate_a(t_stack_needs **a)
{
	rotate_stack(a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack_needs **b)
{
	rotate_stack(b);
	write(1, "rb\n", 3);
}

void	rotate_a_b(t_stack_needs **a, t_stack_needs **b)
{
	rotate_stack(a);
	rotate_stack(b);
	write(1, "rr\n", 3);
}