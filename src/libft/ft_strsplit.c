/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orubin <orubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:10:13 by orubin            #+#    #+#             */
/*   Updated: 2019/09/30 19:48:27 by orubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	tab_size(const char *str, char c)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		while (*str != c && *str)
			str++;
		len++;
		while (*str == c)
			str++;
		str++;
	}
	return (len + 1);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**tab;
	int			i;
	size_t		len;

	if (!s)
		return (NULL);
	while (*s == c)
		s++;
	if (!(tab = (char **)malloc(tab_size(s, c) * sizeof(char *))))
		return (NULL);
	i = 0;
	while (*s)
	{
		len = 0;
		while (*s && *s != c && s++)
			len++;
		tab[i] = ft_strnew(len);
		ft_strncpy(tab[i++], s - len, len);
		while (*s == c)
			s++;
	}
	tab[i] = (char *)0;
	return (tab);
}
