/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 22:52:39 by fford             #+#    #+#             */
/*   Updated: 2019/09/26 20:49:22 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;
	size_t j;
	size_t len;

	len = ft_strlen(needle);
	if (len == 0)
		return ((char*)haystack);
	i = 0;
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j])
		{
			if (j == len - 1)
				return ((char*)&haystack[i]);
			++j;
		}
		++i;
	}
	return (0);
}
