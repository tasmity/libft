/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orubin <orubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 20:25:59 by orubin            #+#    #+#             */
/*   Updated: 2020/03/17 20:14:20 by orubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** %c
** We create a string by adding '\0' to deal with width.
*/

int			ft_get_split(t_flag *mod, int *len)
{
	int		split;

	split = 0;
	if (mod->width && (!mod->flag[1] || mod->flag[3] || mod->prec ||
		mod->prec == 0) && mod->width > *len)
	{
		split = mod->width - *len;
		*len += split;
	}
	return (split);
}

/*
** Fuction counts zeroes, it depends on flags.
*/

int			ft_get_zero(t_flag *mod, int *len, int sign)
{
	int		zero;

	zero = 0;
	if (mod->prec && mod->prec > *len - sign)
	{
		zero = mod->prec - (*len - sign);
		*len += zero;
	}
	if (mod->width && mod->flag[1] && mod->width > *len)
	{
		zero += mod->width - *len;
		*len += zero;
	}
	return (zero);
}

/*
** Checking for ' ' or '+' to output.
** If number is negative, output '-'.
*/

void		ft_print_sign(intmax_t nbr, t_flag *mod)
{
	if (mod->spec == 'd' || mod->spec == 'i')
	{
		if (nbr < 0)
			ft_putchar('-');
		else
		{
			if (mod->flag[2])
				ft_putchar('+');
			else if (mod->flag[4])
				ft_putchar(' ');
		}
	}
}

/*
** Number output.
*/

int			ft_putnbr_all(intmax_t nbr, t_flag *mod)
{
	int		len;
	int		sign;
	int		zero;
	int		split;

	len = 0;
	sign = (nbr >= 0 && (mod->flag[2] || mod->flag[4])) ? 1 : 0;
	mod->prec == -1 || nbr ? len += ft_len_nbr(mod, nbr) : 0;
	mod->prec < len ? mod->prec = -1 : 0;
	len += sign;
	if (nbr < 0 && mod->prec != -1)
	{
		zero = ft_get_zero(mod, &len, sign) + 1;
		len += 1;
	}
	else
		zero = ft_get_zero(mod, &len, sign);
	split = ft_get_split(mod, &len);
	!mod->flag[3] ? ft_nbr_split(split) : 0;
	ft_print_sign(nbr, mod);
	ft_nbr_zero(zero);
	(mod->prec == -1 || nbr) ? ft_print_num(mod, nbr) : 0;
	mod->flag[3] ? ft_nbr_split(split) : 0;
	return (len);
}

/*
** Checking for a number data type.
*/

int			ft_print_d(va_list ap, t_flag *mod)
{
	int		len;
	int		leng;

	leng = mod->leng;
	if (leng == 'l')
		len = ft_putnbr_all(va_arg(ap, long), mod);
	else if (leng == 'K')
		len = ft_putnbr_all(va_arg(ap, long long), mod);
	else if (leng == 'h')
		len = ft_putnbr_all((short)va_arg(ap, int), mod);
	else if (leng == 'H')
		len = ft_putnbr_all((char)va_arg(ap, int), mod);
	else if (leng == 'j')
		len = ft_putnbr_all((intmax_t)va_arg(ap, long long), mod);
	else if (leng == 'z')
		len = ft_putnbr_all((size_t)va_arg(ap, long long), mod);
	else if (leng == 't')
		len = ft_putnbr_all((intptr_t)va_arg(ap, long long), mod);
	else
		len = ft_putnbr_all(va_arg(ap, int), mod);
	return (len);
}
