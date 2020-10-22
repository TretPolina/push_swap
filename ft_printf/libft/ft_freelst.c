/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freelst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 17:20:45 by fford             #+#    #+#             */
/*   Updated: 2019/09/29 14:29:30 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freelst(t_list *lst)
{
	t_list *tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst->content);
		lst->content_size = 0;
		free(lst->next);
		free(lst);
		lst = tmp;
	}
}
