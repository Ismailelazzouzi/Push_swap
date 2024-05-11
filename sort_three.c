/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-azz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 07:51:19 by isel-azz          #+#    #+#             */
/*   Updated: 2024/05/11 07:51:22 by isel-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_needs **a, t_stack_needs **b)
{
	t_stack_needs	*biggest;

	biggest = find_highest(*a);
	if (stack_len(*a) == 2)
		sa(a);
	else
	{
		if (biggest == (*a))
			rotate_a(a);
		else if (biggest == (*a)->next)
			reverse_rotate_a(a);
		if ((*a)->value > (*a)->next->value)
			sa(a);
	}
}
