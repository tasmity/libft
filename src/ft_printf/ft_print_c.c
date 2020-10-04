/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orubin <orubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 20:25:59 by orubin            #+#    #+#             */
/*   Updated: 2020/04/16 05:27:31 by tasmity          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** %c
** We create a string by adding '\0' to deal with width.
*/

int			ft_print_c(va_list ap, t_flag *mod)
{
	char	c;
	size_t	size;
	int		len;
	char	sumb[2];

	c = va_arg(ap, int);
	sumb[0] = c;
	sumb[1] = '\0';
	size = 1;
	len = 1;
	if (mod->width)
		len = ft_print_split(mod, size, sumb);
	else
		ft_putchar(c);
	return (len);
}

int			ft_print_ano(t_flag *mod)
{
	int		size;
	int		length;
	char	a[2];
	char	c;

	c = mod->spec;
	a[0] = c;
	a[1] = '\0';
	size = 1;
	length = 1;
	if (mod->width)
		length = ft_print_split(mod, size, a);
	else
	{
		if (c != '\0' && c != ' ' && !ft_leng(c))
			ft_putchar(c);
		else
			length = 0;
	}
	return (length);
}
