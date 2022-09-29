/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 11:28:03 by rpicot        #+#    #+#                 */
/*   Updated: 2022/08/08 20:17:48 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../../pushswap.h"

t_stack	*reverse_rotate(t_stack *stack_a, t_stack *stack_b,
						int choice, char **lookup)
{
	t_stack	*head;

	if (choice == reverse_rotate_a || choice == reverse_rotate_ab)
		head = stack_a->prev;
	if (choice == reverse_rotate_b || choice == reverse_rotate_ab)
		head = stack_b->prev;
	ft_putstr(lookup[choice], 1);
	return (head);
}
