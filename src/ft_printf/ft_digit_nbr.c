/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orubin <orubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 20:25:59 by orubin            #+#    #+#             */
/*   Updated: 2020/03/17 20:11:13 by orubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Spaces output
*/

int						ft_nbr_split(int split)
{
	int					i;

	i = -1;
	while (++i < split)
		ft_putchar(' ');
	return (i);
}

/*
** Zeroes output
*/

int						ft_nbr_zero(int zero)
{
	int					i;

	i = -1;
	while (++i < zero)
		ft_putchar('0');
	return (i);
}

/*
** Converting number
*/

int						ft_putnum(uintmax_t n, unsigned int base,
							const char *digits)
{
	int					len;

	len = 1;
	if (n >= base)
		len += ft_putnum(n / base, base, digits);
	ft_putchar(digits[n % base]);
	return (len);
}

/*
** Counting number of digits in number
*/

int						ft_putlen(uintmax_t n, unsigned int base)
{
	int					len;

	if (n == 0)
		return (0);
	len = 1;
	if (n >= base)
		len += ft_putlen(n / base, base);
	return (len);
}

int						ft_len_nbr(t_flag *mod, intmax_t nbr)
{
	int					len;
	unsigned long long	u;

	len = (nbr == 0) ? 1 : 0;
	if (mod->spec == 'o')
		len += ft_putlen(nbr, 8);
	else if (mod->spec == 'u')
		len += ft_putlen(nbr, 10);
	else if (mod->spec == 'x' || mod->spec == 'p' || mod->spec == 'X')
		len += ft_putlen(nbr, 16);
	else
	{
		len = (nbr >= 0) ? 1 : 2;
		u = nbr < 0 ? -(unsigned long long)nbr : (unsigned long long)nbr;
		while (u /= 10)
			len++;
	}
	return (len);
}
