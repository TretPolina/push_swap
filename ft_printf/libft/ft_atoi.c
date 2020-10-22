/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:20:47 by fford             #+#    #+#             */
/*   Updated: 2019/09/26 17:21:09 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	num;

	while ((*str == ' ') || (*str == '\t') || (*str == '\r') || (*str == '\n')\
	|| (*str == '\v') || (*str == '\f'))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	num = 0;
	while ((*str >= '0') && (*str <= '9'))
	{
		if (num < 0 && sign == -1)
			return (0);
		else if (num < 0 && sign == 1)
			return (-1);
		num = ((num * 10) + (*str - '0'));
		str++;
	}
	num = num * sign;
	return (num);
}
