/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_push.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 11:28:03 by rpicot        #+#    #+#                 */
/*   Updated: 2022/08/08 20:20:33 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../../pushswap.h"

void	ft_push(t_stack **stack_a, int value)
{
	t_stack	*new_node;
	int		i;

	i = 0;
	new_node = (t_stack *)malloc(sizeof(t_stack));
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (*stack_a)
	{
		(*stack_a)->next = new_node;
		new_node->prev = (*stack_a);
		(*stack_a) = (*stack_a)->next;
	}
	else
		(*stack_a) = new_node;
}
