/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attribut.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orubin <orubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 20:25:59 by orubin            #+#    #+#             */
/*   Updated: 2020/04/16 07:32:10 by tasmity          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** We are checking here for a specifier.
** It is the last one, if there is none -> *format
*/

void		ft_for_spec(char *format, t_flag *mod, int len)
{
	if (len > 0)
		format += len - 1;
	*format == 's' ? mod->spec = 's' : 0;
	*format == 'c' || *format == 'C' ? mod->spec = 'c' : 0;
	*format == 'p' ? mod->spec = 'p' : 0;
	*format == 'd' ? mod->spec = 'd' : 0;
	*format == 'i' ? mod->spec = 'i' : 0;
	*format == 'o' ? mod->spec = 'o' : 0;
	*format == 'u' ? mod->spec = 'u' : 0;
	*format == 'U' ? mod->spec = 'U' : 0;
	*format == 'x' ? mod->spec = 'x' : 0;
	*format == 'X' ? mod->spec = 'X' : 0;
	*format == 'f' ? mod->spec = 'f' : 0;
	*format == '%' ? mod->spec = '%' : 0;
	mod->spec == '\0' ? mod->spec = *format : 0;
}

/*
** Checking for flags: #0+-' '
** If we meet it again, we just ignore it.
*/

int			ft_for_flag(char **format, t_flag *mod)
{
	if (ft_strchr(mod->flag, **format) == NULL)
	{
		**format == '#' ? mod->flag[0] = '#' : 0;
		**format == '0' ? mod->flag[1] = '0' : 0;
		**format == '+' ? mod->flag[2] = '+' : 0;
		**format == '-' ? mod->flag[3] = '-' : 0;
		**format == ' ' ? mod->flag[4] = ' ' : 0;
	}
	return (**format == '#' || **format == '+' || **format == '0' ||
			**format == '-' || **format == ' ');
}

/*
** Filling width
*/

int			ft_for_width(char *format, t_flag *mod, va_list ap)
{
	int		width;
	char	*nbr;

	width = 0;
	if (*format == '*')
	{
		width = va_arg(ap, int);
		if (width < 0)
		{
			width *= -1;
			mod->flag[3] = '-';
		}
		mod->width = width;
		return (1);
	}
	else
	{
		while (ft_isdigit(format[width]))
			width++;
		if (!width || !(nbr = ft_strsub(format, 0, width)))
			return (0);
		mod->width = ft_atoi(nbr);
		free(nbr);
	}
	return (width);
}

/*
** Filling precision
*/

int			ft_for_prec(char *format, t_flag *mod, va_list ap)
{
	int		prec;
	char	*nbr;

	prec = 0;
	if (format[0] == '.')
	{
		prec = 1;
		if (format[1] == '*')
		{
			mod->prec = va_arg(ap, int);
			prec++;
		}
		else
		{
			while (ft_isdigit(format[prec]))
				prec++;
			if (!(nbr = ft_strsub(format, 1, prec)))
				return (0);
			mod->prec = (prec != 1) ? ft_atoi(nbr) : 0;
			free(nbr);
		}
	}
	return (prec);
}

/*
** Filling length
*/

int			ft_for_leng(char *format, t_flag *mod)
{
	int		count;

	count = 0;
	while (format[count] == 'l' || format[count] == 'h'
		|| format[count] == 'L' || format[count] == 'j' || format[count] == 'z'
		|| format[count] == 't')
	{
		if (format[count] == 'l')
			ft_for_l(format, count, mod);
		else if (format[count] == 'h' && mod->leng != 'l' && mod->leng != 'K' &&
			mod->leng != 'j' && mod->leng != 'z' && mod->leng != 't')
			ft_for_h(format, count, mod);
		else if (format[count] == 'L')
			mod->leng = 'L';
		else if (format[count] == 'j')
			mod->leng = 'j';
		else if (format[count] == 'z')
			mod->leng = 'z';
		else if (format[count] == 't')
			mod->leng = 't';
		count++;
		(mod->leng == 'K' || mod->leng == 'H') ? count++ : 0;
	}
	return (count);
}
