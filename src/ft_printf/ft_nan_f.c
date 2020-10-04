/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nan_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orubin <orubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 20:25:59 by orubin            #+#    #+#             */
/*   Updated: 2020/03/23 14:26:29 by tasmity          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_out_nan(t_flag *mod, char *arr)
{
	int		len;

	len = (int)ft_strlen(arr);
	if ((ft_strcmp(arr, "inf") == 0) &&
		mod->flag[4] == ' ' && mod->flag[2] != '+')
	{
		ft_putchar(' ');
		len++;
	}
	if ((ft_strcmp(arr, "inf") == 0) &&
		mod->flag[2] == '+')
		len++;
	if (mod->flag[3] != '-' && len < mod->width)
		len = ft_nbr_split(mod->width - len) + len;
	if ((ft_strcmp(arr, "inf") == 0) &&
		mod->flag[2] == '+')
		ft_putchar('+');
	ft_putstr(arr);
	if (mod->flag[3] == '-' && len < mod->width)
		len = ft_nbr_split(mod->width - len) + len;
	return (len);
}

char		*ft_inf_nan(int cho, long double nbr)
{
	if (cho == 1)
		return ("nan");
	else
	{
		if (nbr < 0)
			return ("-inf");
		else
			return ("inf");
	}
}

void		ft_install(int *power, char **drob, char **ot, int k)
{
	*power = k;
	*drob = ft_strnew_float(5000);
	*ot = NULL;
	if (k >= 0)
		*ot = ft_strnew_float(k);
}

void		ft_norm(int *dt, t_flag *mod)
{
	if (mod->flag[3] == '-')
	{
		(*dt + mod->prec >= mod->width) ? (*dt = mod->prec + *dt) :
		(*dt = ft_nbr_split(mod->width - *dt - mod->prec) + *dt + mod->prec);
	}
}

char		*ft_strnew_float(size_t size)
{
	char	*str;

	if (size + 1 != 0)
	{
		if (!(str = (char *)malloc(sizeof(char) * (size + 2))))
			return (NULL);
		ft_memset(str, '0', size + 1);
		str[size + 1] = '\0';
		return (str);
	}
	return (NULL);
}
