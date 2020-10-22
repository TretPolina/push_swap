/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 21:05:02 by fford             #+#    #+#             */
/*   Updated: 2019/09/22 15:06:10 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (str == NULL)
		return (NULL);
	if (s1 && !s2)
	{
		str = ft_strcpy(str, (char*)s1);
		return (str);
	}
	if (!s1 && s2)
	{
		str = ft_strcpy(str, (char*)s2);
		return (str);
	}
	if (s1 && s2)
	{
		str = ft_strcpy(str, (char*)s1);
		str = ft_strcat(str, (char*)s2);
		return (str);
	}
	return (str);
}
