/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:36:36 by fford             #+#    #+#             */
/*   Updated: 2019/09/21 19:13:09 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest1;
	unsigned char	*src1;

	if (dest == src)
		return (dest);
	dest1 = (unsigned char*)dest;
	src1 = (unsigned char*)src;
	i = -1;
	while (++i < n)
	{
		dest1[i] = src1[i];
	}
	return (dest);
}
