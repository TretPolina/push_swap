/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 23:30:16 by fford             #+#    #+#             */
/*   Updated: 2019/09/21 19:25:20 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t len1;
	size_t len2;

	i = 0;
	j = 0;
	len1 = ft_strlen(dst);
	len2 = ft_strlen(src);
	if (size <= len1)
		return (len2 + size);
	while (dst[i] && i < size - 1)
		++i;
	while (j < len2 && (i + j < size - 1))
	{
		dst[i + j] = src[j];
		++j;
	}
	dst[i + j] = '\0';
	return (ft_strlen(src) + len1);
}
