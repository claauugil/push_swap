/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:22:15 by claudia           #+#    #+#             */
/*   Updated: 2025/01/09 17:57:22 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_depth(t_stack *in_stack, int val)
{
	int		i;
	t_node	*actual;

	i = 0;
	actual = in_stack->top;
	while (actual)
	{
		if (actual->val == val)
		{
			if (i <= in_stack->size / 2)
				return (i);
			else
				return (i - in_stack->size);
		}
		i++;
		actual = actual->next;
	}
	return (INT_MIN);
}

void	bring_to_top(t_stack *a, int target)
{
	int	depth;

	depth = get_depth(a, target);
	while (depth != 0)
	{
		if (depth < 0)
		{
			rra(a);
			depth++;
		}
		if (depth > 0)
		{
			ra(a);
			depth--;
		}
	}
}

void	bring_min_to_top(t_stack *in_stack)
{
	int	min_value;

	if (!in_stack || !in_stack->top)
		return ;
	min_value = find_smallest(in_stack);
	bring_to_top(in_stack, min_value);
}

void	sort_two(t_stack *stack)
{
	if (!stack || !stack->top || !stack->top->next)
		return ;
	if (stack->top->val > stack->top->next->val)
		sa(stack);
}

int	is_sorted(t_stack *stack)
{
	t_node	*actual;

	if (!stack || !stack->top)
		return (1);
	actual = stack->top;
	while (actual && actual->next)
	{
		if (actual->val > actual->next->val)
			return (0);
		actual = actual->next;
	}
	return (1);
}
