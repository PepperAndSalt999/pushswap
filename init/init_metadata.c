/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_metadata.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 11:28:03 by rpicot        #+#    #+#                 */
/*   Updated: 2022/09/22 06:47:15 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../pushswap.h"

static int	get_power(int set_size)
{
	int	i;

	i = 1;
	set_size /= 2;
	while (set_size)
	{
		i++;
		set_size /= 2;
	}
	return (i);
}

static int	fill_array_charnums(int argc, char ***array_charnums, char **argv)
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
		if (!array_charnums[j] || argv[i][0] == 0)
			error_display();
		length += ft_double_strlen(array_charnums[j]);
		i++;
		j++;
	}
	array_charnums[j] = NULL;
	return (length);
}

void	init_metadata(t_metadata *metadata, int argc,
						char ***array_charnums, char **argv)
{
	metadata->stack_size = fill_array_charnums(argc, array_charnums, argv);
	metadata->bit_size = get_power(metadata->stack_size);
}
