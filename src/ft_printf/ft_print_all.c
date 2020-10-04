/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orubin <orubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 20:25:59 by orubin            #+#    #+#             */
/*   Updated: 2020/05/23 19:26:31 by tasmity          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** We check for a specifier and redirect to its function.
** If the specifier is unknown we just output it in last else.
*/

int				ft_read(va_list ap, const char *format)
{
	int			len_at;
	int			count;

	count = 0;
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar(*format);
			count++;
		}
		else
		{
			format++;
			if ((len_at = ft_read_flag(ap, &format)) == -1)
				break ;
			count += len_at;
		}
		format++;
	}
	return (count);
}

int				ft_print_all(va_list ap, t_flag *mod)
{
	int			len;

	ft_off_zero(mod);
	if (mod->spec == 's')
		len = ft_print_s(ap, mod);
	else if (mod->spec == 'c')
		len = ft_print_c(ap, mod);
	else if (mod->spec == 'd' || mod->spec == 'i')
		len = ft_print_d(ap, mod);
	else if (mod->spec == 'u' || mod->spec == 'o' || mod->spec == 'x' ||
		mod->spec == 'X' || mod->spec == 'p' || mod->spec == 'U')
		len = ft_print_u(ap, mod);
	else if (mod->spec == 'f')
		len = ft_print_f(ap, mod);
	else
		len = ft_print_ano(mod);
	return (len);
}

int				ft_print_num(t_flag *mod, intmax_t num)
{
	int			len;

	len = 0;
	if (mod->spec == 'd' || mod->spec == 'i')
		len = ft_print_num_d((intmax_t)num);
	if (mod->spec == 'u' || mod->spec == 'U')
		len = ft_print_num_u((uintmax_t)num);
	if (mod->spec == 'o')
		len = ft_print_num_o((uintmax_t)num);
	if (mod->spec == 'x' || mod->spec == 'p')
		len = ft_print_num_x((uintmax_t)num);
	if (mod->spec == 'X')
		len = ft_print_num_bigx((uintmax_t)num);
	return (len);
}

/*
** We check for a wrong specifier.
*/

int				ft_print_error(const char *format)
{
	int			i;
	const char	*tmp;

	i = 0;
	tmp = format;
	while (tmp[i])
	{
		if (tmp[i] == '%' && i != 0 && tmp[i - 1] != '%' && tmp[i + 1] != '%')
		{
			while (tmp[i])
			{
				if (tmp[i] == 'S')
					return (0);
				i++;
			}
			break ;
		}
		i++;
	}
	return (1);
}

char			*ft_strcpy_f(char *dst, char *src)
{
	int			i;

	i = 0;
	while (src[i] != '\0' && dst[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
