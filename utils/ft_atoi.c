/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 06:44:56 by rpicot        #+#    #+#                 */
/*   Updated: 2022/08/08 20:34:59 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../pushswap.h"

long	ft_atoi(const char *str)
{
	long	neg;
	long	res;
	int		flag;

	flag = 0;
	res = 0;
	neg = 1;
	if (*str == '-')
	{
		flag = 1;
		neg *= -1;
		str++;
	}
	while (*str)
	{
		flag = 0;
		if (!ft_isdigit(*str))
			error_display();
		res *= 10;
		res += *str - '0';
		str++;
	}
	if (flag != 0)
		error_display();
	return (res * neg);
}
