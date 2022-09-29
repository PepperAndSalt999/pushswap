/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_lookup.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 11:28:03 by rpicot        #+#    #+#                 */
/*   Updated: 2022/08/08 19:54:50 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../pushswap.h"

char	**init_lookup(char **lookup)
{
	lookup[0] = "pb\n";
	lookup[1] = "pa\n";
	lookup[2] = "sa\n";
	lookup[3] = "sb\n";
	lookup[4] = "ss\n";
	lookup[5] = "ra\n";
	lookup[6] = "rb\n";
	lookup[7] = "rr\n";
	lookup[8] = "rra\n";
	lookup[9] = "rrb\n";
	lookup[10] = "rrr\n";
	return (lookup);
}
