/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 11:28:03 by rpicot        #+#    #+#                 */
/*   Updated: 2022/08/08 20:17:10 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../../pushswap.h"

static void	basetarget(t_stack **base, t_stack **target, t_stack ***base_target)
{
	base_target[0] = base;
	base_target[1] = target;
}

static void	unlinking(t_stack *node)
{
	if (node->next == node->prev && node->next)
	{
		node->next->prev = NULL;
		node->next->next = NULL;
	}
	if (node->next != node->prev)
	{
		node->next->prev = node->prev;
		node->prev->next = node->next;
	}
	node->next = NULL;
	node->prev = NULL;
}

static void	linking(t_stack *base, t_stack *target)
{
	t_stack	*temp;

	if (target->prev)
	{
		target->prev->next = base;
		temp = target->prev;
	}
	else
	{
		target->next = base;
		temp = target;
	}
	target->prev = base;
	base->prev = temp;
	base->next = target;
}

void	push(t_stack **stack_a, t_stack **stack_b, int choice, char **lookup)
{
	t_stack	**base_target[2];
	t_stack	*temp;

	if (choice == push_a)
		basetarget(stack_a, stack_b, base_target);
	else if (choice == push_b)
		basetarget(stack_b, stack_a, base_target);
	if (*base_target[1])
	{
		temp = (*base_target[0])->next;
		unlinking(*base_target[0]);
		linking(*base_target[0], *base_target[1]);
		*base_target[0] = temp;
		*base_target[1] = (*base_target[1])->prev;
	}
	else
	{
		temp = (*base_target[0])->next;
		unlinking(*base_target[0]);
		*base_target[1] = *base_target[0];
		*base_target[0] = temp;
	}
	ft_putstr(lookup[choice], 1);
}
