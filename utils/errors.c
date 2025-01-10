/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:07:44 by claudia           #+#    #+#             */
/*   Updated: 2025/01/09 18:09:43 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_dups(t_stack *stack)
{
	t_node	*current;
	t_node	*inner;

	current = stack->top;
	while (current != NULL)
	{
		inner = current->next;
		while (inner != NULL)
		{
			if (current->val == inner->val)
				return (1);
			inner = inner->next;
		}
		current = current->next;
	}
	return (0);
}

int	empty_string(char *str)
{
	if (!str || str[0] == '\0')
		return (1);
	while (*str)
	{
		if (*str != ' ' && *str != '\t' && *str != '\n'
			&& *str != '\v' && *str != '\f' && *str != '\r')
			return (0);
		str++;
	}
	return (1);
}

void	print_error(t_stack *a, t_stack *b)
{
	if (*a)
		free
	write(2, "Error\n", 6);
	exit(1);
}
