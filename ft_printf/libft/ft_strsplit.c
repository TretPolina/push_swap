/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fford <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 13:46:20 by fford             #+#    #+#             */
/*   Updated: 2019/09/23 18:27:04 by fford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_words(char const *s, char c)
{
	int	n;

	n = 0;
	while (*s != '\0')
	{
		if (*s == c && *s != '\0')
			s++;
		else
		{
			while (*s != c && *s != '\0')
				s++;
			n++;
		}
	}
	return (n);
}

static void	ft_allfree(char **str, size_t i)
{
	while (i > 0)
	{
		ft_strdel(&str[i]);
		i--;
	}
	ft_strdel(str);
}

static char	*next_word(char const *s, char c, size_t *start)
{
	size_t l;

	while (s[*start] == c)
		*start += 1;
	l = *start;
	while (s[*start])
	{
		if (s[*start] == c)
			break ;
		*start += 1;
	}
	return (ft_strsub(s, l, *start - l));
}

char		**ft_strsplit(char const *s, char c)
{
	int		words;
	size_t	i;
	size_t	start;
	char	**str;

	if (!s)
		return (NULL);
	words = nb_words(s, c);
	str = (char**)malloc(sizeof(char*) * (words + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	start = 0;
	while (words--)
	{
		str[i] = next_word(s, c, &start);
		if (!(str[i]))
			ft_allfree(str, i);
		i++;
	}
	str[i] = NULL;
	return (str);
}
