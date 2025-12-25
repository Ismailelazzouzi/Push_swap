/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-azz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 07:53:15 by isel-azz          #+#    #+#             */
/*   Updated: 2024/05/11 07:53:17 by isel-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_needs	*get_priority(t_stack_needs *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->priority == true)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	rotate_stacks(t_stack_needs **a, t_stack_needs **b,
			t_stack_needs *priority_node)
{
	while (*a != priority_node->target && *b != priority_node)
		rotate_a_b(a, b);
	set_positions(*a);
	set_positions(*b);
}

void	reverse_rotate_stacks(t_stack_needs **a, t_stack_needs **b,
			t_stack_needs *priority_node)
{
	while (*a != priority_node->target && *b != priority_node)
		reverse_rotate_a_b(a, b);
	set_positions(*a);
	set_positions(*b);
}

void	complete(t_stack_needs **stack, t_stack_needs *top, char which)
{
	while (*stack != top)
	{
		if (which == 'a')
		{
			if (top->up_down)
				rotate_a(stack);
			else
				reverse_rotate_a(stack);
		}
		else if (which == 'b')
		{
			if (top->up_down)
				rotate_b(stack);
			else
				reverse_rotate_b(stack);
		}
	}
}

void	freelist(t_stack_needs *a)
{
	t_stack_needs *current = a;
	t_stack_needs *next;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
