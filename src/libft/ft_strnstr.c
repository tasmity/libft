/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orubin <orubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:01:04 by orubin            #+#    #+#             */
/*   Updated: 2019/09/30 19:48:27 by orubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strnstr(const char *hay, const char *need, size_t len)
{
	size_t	size;

	size = ft_strlen(need);
	if (size == 0)
		return ((char *)hay);
	while (*hay && size <= len)
	{
		if (ft_strncmp(hay, need, size) == 0)
			return ((char *)hay);
		hay++;
		len--;
	}
	return (NULL);
}
