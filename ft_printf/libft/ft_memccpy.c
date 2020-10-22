/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 18:50:10 by fford             #+#    #+#             */
/*   Updated: 2019/09/22 13:42:31 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	a;
	unsigned char	*dest1;
	unsigned char	*src1;

	a = c;
	dest1 = (unsigned char*)dest;
	src1 = (unsigned char*)src;
	if (!dest1 && !src1)
		return (NULL);
	while (n-- > 0)
	{
		if ((*dest1 = *src1) == a)
			return (dest1 + 1);
		dest1++;
		src1++;
	}
	return (NULL);
}
