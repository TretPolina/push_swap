/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 22:37:16 by fford             #+#    #+#             */
/*   Updated: 2019/09/26 20:48:27 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	*copy;

	copy = 0;
	str = (char*)s;
	while (*str)
	{
		if (*str == (char)c)
			copy = str;
		++str;
	}
	if (*str == (char)c)
		return (str);
	return (copy);
}
