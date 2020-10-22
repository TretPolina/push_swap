/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 19:03:42 by fford             #+#    #+#             */
/*   Updated: 2019/09/21 20:37:30 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (!needle[j])
		return ((char*)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while ((i + j < len) &&
				(haystack[i + j] == needle[j] && needle[j] != 0))
			++j;
		if (!needle[j])
			return ((char*)&haystack[i]);
		++i;
	}
	return (0);
}
