/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-azz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 07:53:00 by isel-azz          #+#    #+#             */
/*   Updated: 2024/05/11 07:53:03 by isel-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_needs	*get_smallest(t_stack_needs *stack)
{
	long			smallest;
	t_stack_needs	*node;

	if (stack == NULL)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
			node = stack;
		}
		stack = stack->next;
	}
	return (node);
}

void	set_targets(t_stack_needs *a, t_stack_needs *b)
{
	t_stack_needs	*a_now;
	t_stack_needs	*target;
	long			best_match;

	while (b)
	{
		best_match = LONG_MAX;
		a_now = a;
		while (a_now)
		{
			if (a_now->value > b->value && a_now->value < best_match)
			{
				best_match = a_now->value;
				target = a_now;
			}
			a_now = a_now->next;
		}
		if (best_match == LONG_MAX)
			b->target = get_smallest(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	set_push_cost(t_stack_needs *a, t_stack_needs *b)
{
	int	a_len;
	int	b_len;

	a_len = stack_len(a);
	b_len = stack_len(b);
	while (b)
	{
		b->push_cost = b->pos;
		if (!(b->up_down))
			b->push_cost = b_len - (b->pos);
		if (b->target->up_down)
			b->push_cost += b->target->pos;
		else
			b->push_cost += a_len - b->target->pos;
		b = b->next;
	}
}

void	set_positions(t_stack_needs *stack)
{
	int	center;
	int	i;

	if (stack == NULL)
		return ;
	i = 0;
	center = stack_len(stack) / 2;
	while (stack)
	{
		stack->pos = i;
		if (i <= center)
			stack->up_down = true;
		else
			stack->up_down = false;
		stack = stack->next;
		i++;
	}
}

void	set_priority(t_stack_needs *b)
{
	long			best_match;
	t_stack_needs	*node;

	if (b == NULL)
		return ;
	best_match = LONG_MAX;
	while (b)
	{
		if (b->push_cost < best_match)
		{
			best_match = b->push_cost;
			node = b;
		}
		b = b->next;
	}
	node->priority = true;
}
