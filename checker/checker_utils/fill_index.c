/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_index.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 11:28:03 by rpicot        #+#    #+#                 */
/*   Updated: 2022/08/08 19:49:24 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../../pushswap.h"

void	fill_index(t_stack *stack_static)
{
	t_stack	*stack_pivot;
	t_stack	*stack_inner_pivot;
	int		indexing;
	int		greaterthan;

	indexing = 0;
	greaterthan = 0;
	stack_pivot = stack_static;
	while (stack_pivot != stack_static || !indexing)
	{
		indexing = 1;
		stack_inner_pivot = stack_static;
		while (stack_inner_pivot != stack_static->prev)
		{
			if (stack_pivot->value > stack_inner_pivot->value)
				greaterthan++;
			stack_inner_pivot = stack_inner_pivot->next;
		}
		if (stack_pivot->value > stack_inner_pivot->value)
			greaterthan++;
		stack_pivot->index = greaterthan + 1;
		greaterthan = 0;
		stack_pivot = stack_pivot->next;
	}
}
