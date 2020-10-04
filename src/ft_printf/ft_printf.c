/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orubin <orubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 20:25:59 by orubin            #+#    #+#             */
/*   Updated: 2020/04/16 06:28:49 by tasmity          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Checking for length
*/

int				ft_leng(char c)
{
	if (c == 'l' || c == 'h' || c == 'j' || c == 'z' || c == 't' || c == 'L')
		return (1);
	return (0);
}

/*
** We trim a string here.
*/

char			*ft_cut(const char **format)
{
	char		*tmp;
	int			i;

	i = 0;
	tmp = (char *)*format;
	while (tmp[i])
	{
		if (tmp[i] != '.')
		{
			if (!ft_leng(tmp[i]) && !ft_isdigit(tmp[i]) && tmp[i] != '-' &&
				tmp[i] != '+' && tmp[i] != '#' && tmp[i] != ' ' &&
				tmp[i] != '*')
				return (ft_strsub(tmp, 0, i + 1));
		}
		i++;
	}
	return (ft_strdup(*format));
}

/*
** Filling t_flag structure
*/

void			ft_attribut(t_flag *mod, char **tmp, int len, va_list ap)
{
	int			i;

	ft_initialize(mod);
	ft_for_spec(*tmp, mod, len);
	while (**tmp != mod->spec && **tmp != 'C' && len != 0 && **tmp)
	{
		while (ft_for_flag(tmp, mod))
			(*tmp)++;
		while ((i = ft_for_width(*tmp, mod, ap)))
			*tmp += i;
		while ((i = ft_for_prec(*tmp, mod, ap)))
			*tmp += i;
		while ((i = ft_for_leng(*tmp, mod)))
			*tmp += i;
	}
}

/*
** We put parcer into tmp;
** checking for width, precision and specifier
*/

int				ft_read_flag(va_list ap, const char **format)
{
	t_flag		mod;
	int			len;
	char		*tmp;
	char		*start;
	int			len_at;

	tmp = ft_cut(format);
	start = tmp;
	len = (int)ft_strlen(tmp);
	ft_attribut(&mod, &tmp, len, ap);
	len_at = ft_print_all(ap, &mod);
	len != 0 ? *format += (len - 1) : 0;
	tmp = start;
	free(tmp);
	tmp = NULL;
	if (!**format)
		return (-1);
	return (len_at);
}

/*
** Main function
** If we meet %, redirect to fuction, otherwise output characters.
** Return value is number of printed characters.
*/

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			count;

	va_start(ap, format);
	if (!ft_print_error(format))
		return (-1);
	count = ft_read(ap, format);
	va_end(ap);
	return (count);
}
