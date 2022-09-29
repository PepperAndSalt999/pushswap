/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loop_through_char_nums.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 11:28:03 by rpicot        #+#    #+#                 */
/*   Updated: 2022/08/08 19:52:17 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../../pushswap.h"

void	loop_through_char_nums(char **array_charnums, t_stack **stack_a)
{
	int		j;
	int		i;
	long	number;

	i = 0;
	j = 0;
	number = 0;
	while (array_charnums[j])
	{
		number = ft_atoi(array_charnums[j]);
		if (number > 2147483647 || number < -2147483648)
			error_display();
		else
			ft_push(stack_a, number);
		j++;
	}
}
