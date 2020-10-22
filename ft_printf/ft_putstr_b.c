/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <fford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 19:52:23 by fford             #+#    #+#             */
/*   Updated: 2020/03/06 18:55:50 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_putstr_bytes(char const *s, t_spec *spec)
{
	if (!s)
		return ;
	while (*s != '\0')
	{
		write(1, s, 1);
		s++;
		spec->bytes++;
	}
}
