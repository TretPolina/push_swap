/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:26:02 by fford             #+#    #+#             */
/*   Updated: 2019/09/22 19:28:14 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	*revers;

	len = ft_strlen(str);
	revers = (char*)malloc(len + 1);
	if (revers == NULL)
		return (NULL);
	i = 0;
	while (len > 0)
	{
		revers[i] = str[len - 1];
		i++;
		len--;
	}
	return (revers);
}
