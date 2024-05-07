#include "push_swap.h"

void	create_stack(char **numbers, t_stack_needs **stack_a)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (numbers[i] != NULL)
	{
		nbr = ft_atoi(numbers[i], numbers);
		add_node(stack_a, nbr);
		i++;
	}
	if (*stack_a != NULL)
		free_numbers(numbers, 0);
}

void	add_node(t_stack_needs **stack, int nbr)
{
	t_stack_needs	*node_to_add;
	t_stack_needs	*last_node;

	if (stack == NULL)
		return ;
	node_to_add = malloc(sizeof(t_stack_needs));
	if (node_to_add == NULL)
		return ;
	node_to_add->next = NULL;
	node_to_add->value = nbr;
	if (*stack == NULL)
	{
		*stack = node_to_add;
		node_to_add->prev = NULL;
	}
	else
	{
		last_node = get_last_node(*stack);
		last_node->next = node_to_add;
		node_to_add->prev = last_node;
	}
}

t_stack_needs	*get_last_node(t_stack_needs *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
