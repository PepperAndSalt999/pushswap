/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_stack_main.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 08:15:03 by rpicot        #+#    #+#                 */
/*   Updated: 2022/09/22 06:26:42 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../pushswap.h"

void	push_all_b(t_stack **stack_a, t_stack **stack_b, char **lookup)
{
	while (*stack_b)
		push(stack_a, stack_b, push_b, lookup);
}

void	sort_stack_main(t_stack *stack_a, t_stack *stack_b,
						char **lookup, t_metadata *metadata)
{
	int	mask;
	int	size;

	mask = 1;
	if (!is_stack_sorted(stack_a))
	{
		while (metadata->bit_size)
		{
			size = metadata->stack_size;
			while (size)
			{
				if (stack_a->index & mask)
					stack_a = rotate(stack_a, stack_b, rotate_a, lookup);
				else
					push(&stack_a, &stack_b, push_a, lookup);
				size--;
			}
			push_all_b(&stack_a, &stack_b, lookup);
			mask <<= 1;
			metadata->bit_size--;
		}
	}
}

static void	insert(t_stack *stack_a, t_stack *stack_b, char **lookup)
{
	int	count;

	count = 3;
	while (stack_b)
	{
		if (stack_b->value < stack_a->value || count == 0)
		{
			push(&stack_a, &stack_b, push_b, lookup);
			count++;
		}
		if (stack_b)
			stack_a = rotate(stack_a, stack_b, rotate_a, lookup);
		count--;
	}
	fill_index(stack_a);
	while (1)
	{
		if (stack_a->index != 1)
			stack_a = rotate(stack_a, stack_b, rotate_a, lookup);
		else
			break ;
	}
}

t_stack	*sort_three(t_stack *stack_a, t_stack *stack_b, char **lookup)
{
	if ((stack_a->index == 3 && stack_a->next->index == 2)
		|| (stack_a->index == 1 && stack_a->next->index == 3))
		swap(stack_a, stack_b, swap_a, lookup);
	if (stack_a->index == 2)
	{
		if (stack_a->next->index == 1)
			swap(stack_a, stack_b, swap_a, lookup);
		else
			stack_a = reverse_rotate(stack_a, stack_b,
					reverse_rotate_a, lookup);
	}
	else if (stack_a->index != 1 || stack_a->next->index != 2)
		stack_a = rotate(stack_a, stack_b, rotate_a, lookup);
	return (stack_a);
}

void	sort_five(t_stack *stack_a, t_stack *stack_b,
				char **lookup, t_metadata *metadata)
{
	int	pivot;

	pivot = metadata->stack_size;
	while (metadata->stack_size > 3)
	{
		push(&stack_a, &stack_b, push_a, lookup);
		metadata->stack_size--;
	}
	fill_index(stack_a);
	stack_a = sort_three(stack_a, stack_b, lookup);
	if (stack_b->next && stack_b->index > stack_b->next->index)
		swap(stack_a, stack_b, swap_b, lookup);
	insert(stack_a, stack_b, lookup);
}
