/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orubin <orubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 20:25:59 by orubin            #+#    #+#             */
/*   Updated: 2020/05/23 21:24:18 by tasmity          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** extracting the value of the fractional part
*/

int				ft_long_arifm_drob(char *drob, t_flag *mod, char *res)
{
	int			power;
	char		*res_drob;
	char		*tmp;
	int			max;

	power = 1;
	max = ft_find_max(drob);
	res_drob = ft_strnew_float(5000);
	while (*drob != '\0')
	{
		if (*drob == '1')
		{
			tmp = ft_strnew_float(5000);
			tmp = ft_mult_five(power, 5000, tmp, max);
			res_drob = ft_sum(tmp, res_drob, 5000);
			free(tmp);
		}
		power++;
		drob++;
	}
	(mod->zero == 0) ? (res_drob[5000 - max - 1] = '.') :
		(res_drob[5000 - max] = '.');
	power = ft_prec_f(res_drob, mod, res);
	free(res_drob);
	return (power);
}

/*
** extracting the value of the integer part
*/

int				ft_long_arifm_ot(char *ot, char *drob, int power,
				t_flag *mod)
{
	char		*res;
	char		*tmp;
	int			size;
	int			width;

	size = 5000;
	res = ft_strnew_float(5000);
	while (ot != NULL && *ot != '\0')
	{
		if (*ot == '1')
		{
			tmp = ft_strnew_float(size);
			tmp = ft_mult_two(power, size, tmp);
			res = ft_sum(tmp, res, size);
			free(tmp);
		}
		power--;
		ot++;
	}
	width = ft_long_arifm_drob(drob, mod, res);
	free(res);
	return (width);
}

/*
** filling in a bitwise array for the integer and fractional parts of a number
*/

int				ft_help_f(int k, t_float_u flo, t_flag *mod)
{
	int			i;
	int			power;
	char		*drob;
	char		*ot;

	ft_install(&power, &drob, &ot, k);
	i = 64;
	while (i--)
	{
		if (k >= 0)
		{
			if ((flo.bytes.mantisa >> i) & 1)
				ot[power - k] = '1';
		}
		else
		{
			if ((flo.bytes.mantisa >> i) & 1)
				drob[-k - 1] = '1';
		}
		k--;
	}
	i = ft_long_arifm_ot(ot, drob, power, mod);
	free(ot);
	free(drob);
	return (i);
}

/*
** (flo.bytes.sign) & 1)
** even - 0; odd - (1 -> 1) when -1, 0 when 0
*/

int				ft_double_f(long double nbr, t_flag *mod)
{
	int			len;
	int			k;
	t_float_u	flo;

	if (nbr != nbr)
		return (ft_out_nan(mod, ft_inf_nan(1, nbr)));
	if (nbr / 10 == nbr * 10 && nbr != 0)
		return (ft_out_nan(mod, ft_inf_nan(0, nbr)));
	ft_check_drob(nbr, mod);
	flo.f = nbr;
	k = flo.bytes.exponent - 16383;
	if ((flo.bytes.sign) & 1)
	{
		mod->leng = 1;
		len = ft_help_f(k, flo, mod);
	}
	else
	{
		mod->leng = 0;
		len = ft_help_f(k, flo, mod);
	}
	return (len);
}

int				ft_print_f(va_list ap, t_flag *mod)
{
	int			len;
	int			length;

	len = 0;
	length = mod->leng;
	if (mod->prec == -1)
		mod->prec = 6;
	if (length == 'L')
		len = ft_double_f(va_arg(ap, long double), mod);
	else
		len = ft_double_f((long double)va_arg(ap, double), mod);
	return (len);
}
