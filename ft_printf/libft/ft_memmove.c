/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:45:55 by fford             #+#    #+#             */
/*   Updated: 2019/09/22 13:33:13 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest1;
	unsigned char	*src1;

	dest1 = (unsigned char*)dest;
	src1 = (unsigned char*)src;
	i = 0;
	if (!dest1 && !src1)
		return (NULL);
	if (dest1 > src1)
	{
		while (++i <= n)
			dest1[n - i] = src1[n - i];
	}
	else
		while (n-- > 0)
			*(dest1++) = *(src1++);
	return (dest);
}
