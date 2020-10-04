/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orubin <orubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:25:59 by orubin            #+#    #+#             */
/*   Updated: 2020/03/17 20:14:20 by orubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_put_mnum(t_flag *mod, int len, int *zero, int *split)
{
	*zero = mod->prec - len;
	*split = mod->width - mod->prec;
	len = len + *zero + *split;
	return (len);
}

void		ft_print_pref(t_flag *mod, uintmax_t nbr)
{
	if ((mod->spec == 'x' && mod->flag[0] && nbr) || mod->spec == 'p')
		ft_putstr("0x");
	else if (mod->spec == 'X' && mod->flag[0] && nbr)
		ft_putstr("0X");
	else if (mod->spec == 'o' && mod->flag[0] && nbr)
		ft_putchar('0');
}

int			ft_put_sign(t_flag *mod, uintmax_t nbr)
{
	if (nbr && mod->flag[0])
	{
		if (mod->spec == 'x' || mod->spec == 'X')
			return (2);
		else if (mod->spec == 'o')
		{
			mod->prec -= 1;
			return (1);
		}
	}
	else if (mod->flag[0] && mod->spec == 'o' && mod->prec == 0)
	{
		mod->prec -= 1;
		return (1);
	}
	else if (mod->spec == 'p')
		return (2);
	return (0);
}

int			ft_unsigned_u(uintmax_t nbr, t_flag *mod)
{
	int		len;
	int		zero;
	int		split;
	int		sign;

	len = mod->prec == -1 || nbr ? ft_len_nbr(mod, nbr) : 0;
	sign = ft_put_sign(mod, nbr);
	len += sign;
	if (mod->prec != -1 && mod->prec <= mod->width && mod->flag[1] &&
		len < mod->prec)
		len = ft_put_mnum(mod, len, &zero, &split);
	else
	{
		zero = ft_get_zero(mod, &len, sign);
		split = ft_get_split(mod, &len);
	}
	!mod->flag[3] ? ft_nbr_split(split) : 0;
	ft_print_pref(mod, nbr);
	ft_nbr_zero(zero);
	(mod->prec == -1 || nbr) ? ft_print_num(mod, nbr) : 0;
	mod->flag[3] ? ft_nbr_split(split) : 0;
	return (len);
}

int			ft_print_u(va_list ap, t_flag *mod)
{
	int		len;
	int		length;

	length = mod->leng;
	if (length == 'K')
		len = ft_unsigned_u(va_arg(ap, unsigned long long), mod);
	else if (length == 'l')
		len = ft_unsigned_u(va_arg(ap, unsigned long), mod);
	else if (length == 'h' && mod->spec != 'U')
		len = ft_unsigned_u((unsigned short)va_arg(ap, unsigned int), mod);
	else if (length == 'H')
		len = ft_unsigned_u((unsigned char)va_arg(ap, unsigned int), mod);
	else if (length == 'j')
		len = ft_unsigned_u((uintmax_t)va_arg(ap, unsigned long long), mod);
	else if (mod->spec == 'p')
		len = ft_unsigned_u((uintmax_t)va_arg(ap, void *), mod);
	else if (mod->spec == 'U')
		len = ft_unsigned_u((uintmax_t)va_arg(ap, unsigned long), mod);
	else
		len = ft_unsigned_u(va_arg(ap, unsigned int), mod);
	return (len);
}
