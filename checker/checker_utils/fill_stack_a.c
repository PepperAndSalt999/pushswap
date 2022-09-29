/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_stack_a.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 11:28:03 by rpicot        #+#    #+#                 */
/*   Updated: 2022/08/08 19:50:27 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../../pushswap.h"

void	fill_stack_a(char ***array_charnums, t_stack **stack_a)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (array_charnums[i])
	{
		loop_through_char_nums(array_charnums[i], stack_a);
		i++;
	}
	link_last_nodes(stack_a);
}
