/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 08:28:11 by rpicot        #+#    #+#                 */
/*   Updated: 2022/03/25 08:28:21 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../pushswap.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	srclen_with_term_char;

	srclen_with_term_char = ft_strlen(src) + 1;
	if (dstsize >= srclen_with_term_char)
		ft_memcpy(dest, src, srclen_with_term_char);
	else if (dstsize > 0)
	{
		ft_memcpy(dest, src, dstsize - 1);
		dest[dstsize - 1] = '\0';
	}
	return (srclen_with_term_char - 1);
}
