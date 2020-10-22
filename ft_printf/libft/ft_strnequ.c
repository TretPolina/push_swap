/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:18:52 by fford             #+#    #+#             */
/*   Updated: 2019/09/23 19:52:29 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	if (n == 0)
		return (1);
	if (s1 && s2 && n)
	{
		while (n > 0)
		{
			if (s1[n - 1] != s2[n - 1])
				return (0);
			n--;
		}
		return (1);
	}
	return (0);
}
