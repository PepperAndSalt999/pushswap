/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   link_last_nodes.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 11:28:03 by rpicot        #+#    #+#                 */
/*   Updated: 2022/08/08 19:51:11 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../../pushswap.h"

void	link_last_nodes(t_stack **stack)
{
	t_stack	*last_node;

	last_node = *stack;
	*stack = ft_lstfirst(*stack);
	(*stack)->prev = last_node;
	last_node->next = (*stack);
}
