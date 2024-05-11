/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-azz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 07:51:52 by isel-azz          #+#    #+#             */
/*   Updated: 2024/05/11 07:51:54 by isel-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack_needs **stack)
{
	if (stack == NULL || *stack == NULL || stack_len(*stack) <= 1)
		return ;
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

void	sa(t_stack_needs **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack_needs **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack_needs **a, t_stack_needs **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
