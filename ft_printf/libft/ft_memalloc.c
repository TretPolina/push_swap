/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:18:56 by fford             #+#    #+#             */
/*   Updated: 2019/09/26 20:51:27 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*memory;

	memory = (void*)malloc(size);
	if (memory == NULL)
		return (NULL);
	ft_bzero(memory, size);
	return (memory);
}
