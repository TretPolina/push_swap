/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 20:16:37 by fford             #+#    #+#             */
/*   Updated: 2019/09/22 19:25:23 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_size(int nb)
{
	int	size;

	size = 1;
	while (nb /= 10)
		++size;
	return (size);
}

char		*ft_itoa(int n)
{
	char				*str;
	int					size;
	unsigned int		n_cpy;

	size = nb_size(n);
	n_cpy = n;
	if (n < 0)
	{
		n_cpy = -n;
		size++;
	}
	if (!(str = ft_strnew(size)))
		return (NULL);
	str[--size] = n_cpy % 10 + '0';
	while (n_cpy /= 10)
		str[--size] = n_cpy % 10 + '0';
	if (n < 0)
		*(str + 0) = '-';
	return (str);
}
