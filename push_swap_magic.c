/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_magic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-azz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 07:46:07 by isel-azz          #+#    #+#             */
/*   Updated: 2024/05/11 07:46:11 by isel-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert(t_stack_needs **a, t_stack_needs **b)
{
	t_stack_needs	*priority_node;

	priority_node = get_priority(*b);
	if (priority_node->up_down
		&& priority_node->target->up_down)
		rotate_stacks(a, b, priority_node);
	else if (!(priority_node->up_down)
		&& !(priority_node->target->up_down))
		reverse_rotate_stacks(a, b, priority_node);
	complete(b, priority_node, 'b');
	complete(a, priority_node->target, 'a');
	push_a(a, b);
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
	sort_three(a, b);
	while (*b)
	{
		start_nodes(*a, *b);
		insert(a, b);
	}
	set_positions(*a);
	smallest = get_smallest(*a);
	if (smallest->up_down)
		while (*a != smallest)
			rotate_a(a);
	else
		while (*a != smallest)
			reverse_rotate_a(a);
}
