/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker_main.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 06:22:28 by rpicot        #+#    #+#                 */
/*   Updated: 2022/08/08 17:19:01 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../pushswap.h"

static void	fill_stack_a(char ***array_charnums, t_stack **stack_a)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (array_charnums[i])
	{
		loop_through_char_nums(array_charnums[i], stack_a);
		i++;
	}
	link_last_nodes(stack_a);
}

static void	check_duplicates(t_stack *stack_a)
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

void	checker_main(t_stack **stack_a, char ***array_charnums)
{
	fill_stack_a(array_charnums, stack_a);
	check_duplicates(*stack_a);
	fill_index(*stack_a);
}
