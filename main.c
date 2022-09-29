/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 06:22:18 by rpicot        #+#    #+#                 */
/*   Updated: 2022/09/29 15:45:57 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./pushswap.h"

int	main(int argc, char **argv)
{
	t_stack			*stacks[2];
	t_metadata		metadata;
	char			***array_charnums;
	char			*lookup[12];

	array_charnums = NULL;
	if (argc >= 2)
	{
		array_charnums = malloc(sizeof(char **) * (argc + 1));
		if (!array_charnums)
			exit(0);
		init_stacks(stacks);
		init_metadata(&metadata, argc, array_charnums, argv);
		checker_main(&stacks[0], array_charnums);
		init_lookup(lookup);
		if (metadata.stack_size < 2 || is_stack_sorted(stacks[0]))
			exit(0);
		if (metadata.stack_size <= 3)
			stacks[0] = sort_three(stacks[0], stacks[1], lookup);
		else if (metadata.stack_size <= 5)
			sort_five(stacks[0], stacks[1], lookup, &metadata);
		else
			sort_stack_main(stacks[0], stacks[1], lookup, &metadata);
	}
	exit(0);
}
