/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-azz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 07:52:48 by isel-azz          #+#    #+#             */
/*   Updated: 2024/05/11 07:52:50 by isel-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_numbers(char **numbers, int flag)
{
	int	i;

	i = 0;
	while (numbers[i] != NULL)
		i++;
	while (i >= 0)
		free(numbers[i--]);
	free(numbers);
	if (flag == 1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

int	stack_len(t_stack_needs *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int	is_sorted(t_stack_needs *stack)
{
	if (stack == NULL)
		return (0);
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_stack_needs	*find_highest(t_stack_needs *stack)
{
	t_stack_needs	*node;
	int				highest;

	highest = INT_MIN;
	while (stack)
	{
		if (stack->value > highest)
		{
			highest = stack->value;
			node = stack;
		}
		stack = stack->next;
	}
	return (node);
}
