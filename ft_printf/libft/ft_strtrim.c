/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 12:55:36 by fford             #+#    #+#             */
/*   Updated: 2019/09/23 00:31:57 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		start;
	int		end;
	int		i;

	if (!s)
		return (NULL);
	start = 0;
	while ((s[start] == ' ') || (s[start] == '\t') || (s[start] == '\n'))
		start++;
	end = ft_strlen(s) - 1;
	while ((s[end] == ' ') || (s[end] == '\t') || (s[end] == '\n'))
		end--;
	if (end < 0)
		return (ft_strnew(0));
	str = ft_strnew(end - start + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (start <= end)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
