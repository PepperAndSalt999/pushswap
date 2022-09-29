/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 11:28:03 by rpicot        #+#    #+#                 */
/*   Updated: 2022/08/08 20:15:14 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../../pushswap.h"

t_stack	*rotate(t_stack *stack_a, t_stack *stack_b, int choice, char **lookup)
{
	t_stack	*head;

	if (choice == rotate_a || choice == rotate_ab)
		head = stack_a->next;
	if (choice == rotate_b || choice == rotate_ab)
		head = stack_b->next;
	ft_putstr(lookup[choice], 1);
	return (head);
}
