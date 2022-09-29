/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 08:34:28 by rpicot        #+#    #+#                 */
/*   Updated: 2022/03/25 08:34:38 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../pushswap.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*sourc;
	int				i;

	i = 0;
	dest = (unsigned char *)dst;
	sourc = (unsigned char *)src;
	if (!dest && !sourc)
		return (NULL);
	while (n)
	{
		dest[i] = sourc[i];
		n--;
		i++;
	}
	return (dst);
}
