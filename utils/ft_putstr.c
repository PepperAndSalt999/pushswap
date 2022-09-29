/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/26 05:34:45 by rpicot        #+#    #+#                 */
/*   Updated: 2022/08/08 20:36:50 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../pushswap.h"

void	ft_putstr(char *str, int code)
{
	while (*str)
	{
		write(code, str, 1);
		str++;
	}
}
