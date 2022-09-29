/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_array_charnums.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 11:28:03 by rpicot        #+#    #+#                 */
/*   Updated: 2022/08/08 19:47:46 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../../pushswap.h"

int	fill_array_charnums(int argc, char ***array_charnums, char **argv)
{
	int	i;
	int	j;
	int	length;

	i = 1;
	j = 0;
	length = 0;
	while (i < argc)
	{
		array_charnums[j] = ft_split(argv[i], ' ');
		if (!array_charnums[j])
			return (0);
		length += ft_double_strlen(array_charnums[j]);
		i++;
		j++;
	}
	array_charnums[j] = NULL;
	return (length);
}
