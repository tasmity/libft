/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orubin <orubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 20:25:59 by orubin            #+#    #+#             */
/*   Updated: 2020/03/17 20:14:20 by orubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Precision cuts number of characters to output,
** width fills with spaces, zeroes or spreads.
*/

/*
** Printing precision symbols
*/

int			ft_print_prec(t_flag *mod, size_t size, char *str)
{
	int		i;

	i = -1;
	if (mod->prec != -1)
		while (++i < mod->prec && str[i])
			ft_putchar(str[i]);
	else
		while (++i < (int)size)
			ft_putchar(str[i]);
	return (i);
}

/*
** We print characters first, after we print spaces.
** Width with '-'.
*/

int			ft_split_second(t_flag *mod, size_t size, char *str)
{
	int		i;
	int		split;
	int		sumb;

	i = -1;
	if (mod->prec == -1 || str[i + 1] == '\0' || mod->prec >= (int)size)
		split = mod->width - (int)size;
	else
		split = mod->width - mod->prec;
	sumb = ft_print_prec(mod, size, str);
	if (split < 0)
		split *= -1;
	while (++i < split)
		ft_putchar(' ');
	return (split + sumb);
}

/*
** We print spaces or zeroes first, after we print characters.
** Width with '0' or without flags.
*/

int			ft_split_first(t_flag *mod, size_t size, char *str)
{
	int		split;
	int		zero;
	int		i;

	i = -1;
	zero = mod->flag[1];
	if (mod->prec == -1 || (mod->width >= mod->prec && mod->prec > (int)size) ||
		(mod->width < mod->prec && mod->prec > (int)size &&
		mod->width >= (int)size) || str[i + 1] == '\0')
		split = mod->width - (int)size;
	else
		split = mod->prec == -1 ? mod->width - mod->prec - 1 :
				mod->width - mod->prec;
	split < 0 ? split *= -1 : 0;
	while (++i < split)
	{
		if (!zero)
			ft_putchar(' ');
		else if (mod->width >= (int)size)
			ft_putchar('0');
		else
			break ;
	}
	return (i + ft_print_prec(mod, size, str));
}

/*
** Checking for output here, depends on flag.
*/

int			ft_print_split(t_flag *mod, size_t size, char *str)
{
	int		width;
	int		prec;
	int		bool;

	width = mod->width;
	prec = mod->prec;
	bool = mod->flag[3];
	if (!width || (width < prec && width <= (int)size) ||
		(bool && width < prec && width <= (int)size) ||
		(width < (int)size && prec == -1))
		return (ft_print_prec(mod, size, str));
	else if ((bool && width <= prec) || (bool && width > prec))
		return (ft_split_second(mod, size, str));
	else if (width == prec || width > prec || (bool && !width) ||
		(width < prec && prec > (int)size && width + size))
		return (ft_split_first(mod, size, str));
	return (0);
}

int			ft_print_s(va_list ap, t_flag *mod)
{
	char	*str;
	size_t	size;
	int		len;
	int		flag;

	flag = 0;
	if (!(str = va_arg(ap, char *)))
	{
		str = ft_strdup("(null)");
		flag = 1;
	}
	size = ft_strlen(str);
	if (mod->prec != -1 || mod->width != 0)
	{
		len = ft_print_split(mod, size, str);
		if (flag == 1)
			free(str);
		return (len);
	}
	ft_putstr(str);
	flag == 1 ? free(str) : 0;
	return ((int)size);
}
