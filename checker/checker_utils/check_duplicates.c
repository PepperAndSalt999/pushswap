/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_duplicates.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 11:28:03 by rpicot        #+#    #+#                 */
/*   Updated: 2022/08/08 19:45:49 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../../pushswap.h"

void	check_duplicates(t_stack *stack_a)
{
	t_stack	*temp_stack;
	t_stack	*stack_a_cpy;

	stack_a_cpy = stack_a;
	while (stack_a != stack_a_cpy->prev)
	{
		temp_stack = stack_a->next;
		while (temp_stack != stack_a_cpy)
		{
			if (stack_a->value == temp_stack->value)
				error_display();
			temp_stack = temp_stack->next;
		}
		stack_a = stack_a->next;
	}
}
