/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_sorted.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 08:15:03 by rpicot        #+#    #+#                 */
/*   Updated: 2022/08/08 20:24:17 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../pushswap.h"

int	is_stack_sorted(t_stack *stack_a)
{
	t_stack	*head;

	if (!stack_a)
		return (0);
	head = stack_a;
	while (stack_a != head->prev)
	{
		if (stack_a->value > stack_a->next->value)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}
