/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:32:17 by fford             #+#    #+#             */
/*   Updated: 2019/09/23 18:30:10 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t len;
	size_t j;

	len = ft_strlen(dest);
	j = 0;
	while (src[j] != '\0' && j < n)
	{
		dest[len + j] = src[j];
		j++;
	}
	dest[len + j] = '\0';
	return (dest);
}
