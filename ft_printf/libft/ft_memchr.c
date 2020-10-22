/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:31:10 by fford             #+#    #+#             */
/*   Updated: 2019/09/26 20:43:51 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	cc;

	str = (unsigned char*)s;
	cc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == cc)
			return (str + i);
		i++;
	}
	return (NULL);
}
