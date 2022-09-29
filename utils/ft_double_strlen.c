/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_double_strlen.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 08:15:03 by rpicot        #+#    #+#                 */
/*   Updated: 2022/08/08 20:36:27 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../pushswap.h"

int	ft_double_strlen(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
