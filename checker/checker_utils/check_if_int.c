/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_if_int.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 06:54:01 by rpicot        #+#    #+#                 */
/*   Updated: 2022/03/28 06:18:38 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../../pushswap.h"

int	check_if_int(long number)
{
	if (number > 2147483647 || number < -2147483648)
		return (0);
	else
		return (number);
}
