#include "push_swap.h"

void	push(t_stack_needs **dest, t_stack_needs **src)
{
	t_stack_needs	*node;

	if (*src == NULL)
		return ;
	node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node->prev = NULL;
	if (*dest == NULL)
	{
		*dest = node;
		node->next = NULL;
	}
	else
	{
		node->next = *dest;
		node->next->prev = node;
		*dest = node;
	}
}

void	push_a(t_stack_needs **a, t_stack_needs **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	push_b(t_stack_needs **a, t_stack_needs **b)
{
	push(b, a);
	write(1, "pb\n", 3);
}