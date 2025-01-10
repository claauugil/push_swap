/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:16:29 by claudia           #+#    #+#             */
/*   Updated: 2025/01/09 19:19:04 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->val = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	return (stack);
}

void	push_stack(t_stack *stack, int value)
{
	t_node	*node;

	node = new_node(value);
	if (!node)
		return ;
	if (stack->size == 0)
	{
		stack->top = node;
		stack->bottom = node;
	}
	else
	{
		node->next = stack->top;
		stack->top->prev = node;
		stack->top = node;
	}
	stack->size++;
}

void	init_stack(int ac, char *av[], t_stack *stack)
{
	int		i;
	char	**nums;

	if (ac == 2)
	{
		nums = ft_split(av[1], ' ');
		i = 0;
		while (nums && nums[i])
			i++;
		while (i > 0)
		{
			i--;
			push_stack(stack, ft_atoi(nums[i]));
		}
		free_split(nums);
	}
	else
	{
		i = ac -1;
		while (i > 0)
		{
			push_stack(stack, ft_atoi(av[i]));
			i--;
		}
	}
}

void	free_stack(t_stack *stack)
{
	t_node	*actual;
	t_node	*temp;

	actual = stack->top;
	while (actual)
	{
		temp = actual;
		actual = actual->next;
		free(temp);
	}
	free(stack);
}
