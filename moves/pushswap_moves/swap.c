/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 11:28:03 by rpicot        #+#    #+#                 */
/*   Updated: 2022/08/08 20:19:11 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../../pushswap.h"

static void	cpy_index(t_stack *stack_a)
{
	int	index;

	index = stack_a->index;
	stack_a->index = stack_a->next->index;
	stack_a->next->index = index;
}

static void	cpy_value(t_stack *stack_a)
{
	int	value;

	value = stack_a->value;
	stack_a->value = stack_a->next->value;
	stack_a->next->value = value;
}

void	swap(t_stack *stack_a, t_stack *stack_b, int choice, char **lookup)
{
	if (choice == swap_a || choice == swap_ab)
	{
		cpy_index(stack_a);
		cpy_value(stack_a);
	}
	if (choice == swap_b || choice == swap_ab)
	{
		cpy_index(stack_b);
		cpy_value(stack_b);
	}
	ft_putstr(lookup[choice], 1);
}
