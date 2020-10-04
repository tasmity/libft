/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orubin <orubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 20:25:59 by orubin            #+#    #+#             */
/*   Updated: 2020/05/31 00:26:40 by tasmity          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** find the first bit from the end in the fractional part of the number
*/

int			ft_find_max(char *arr)
{
	int		count;
	int		i;

	i = (int)ft_strlen(arr);
	count = 0;
	while (arr[i - count - 1] == '0' && count < 5000)
		count++;
	return (i - count);
}

int			ft_find_val(char *drob, t_flag *mod)
{
	int		i;

	i = mod->zero != 5 ? mod->prec : mod->prec + 1;
	if (mod->zero != 5 && (int)ft_strlen(drob) <= mod->prec)
		return (0);
	if (mod->zero == 5 && (int)ft_strlen(drob) + 1 <= mod->prec + 1)
		return (0);
	mod->zero == 5 ? i -= 1 : 0;
	while (drob[++i] != '\0')
		if (drob[i] > '0')
			return (1);
	return (0);
}

/*
** rounding fractions
*/

int			ft_bonus_helprec_1(char *p, t_flag *mod, char **drob)
{
	if (mod->zero == 5)
	{
		if ((p = ft_strnew_float(mod->prec)))
		{
			p[mod->prec] = '1';
			*drob = ft_sum(p, *drob, mod->prec);
		}
	}
	else if ((p = ft_strnew_float(mod->prec - 1)))
	{
		p[mod->prec - 1] = '1';
		*drob = ft_sum(p, *drob, mod->prec - 1);
	}
	else if ((p = ft_strnew_float(0)))
	{
		p[0] = '1';
		*drob = ft_sum(p, *drob, 0);
	}
	free(p);
	return (0);
}

void		ft_sum_1(char **drob, t_flag *mod, char **res, char *p)
{
	if (*drob != NULL && mod->prec == 0 && (((*drob)[0] >= '5' &&
		((*res)[5000] - '0') % 2 != 0) || (*drob)[0] > '5'))
	{
		p = ft_strnew_float(ft_strlen(*res));
		p[ft_strlen(*res) - 1] = '1';
		*res = ft_sum(p, *res, (int)ft_strlen(*res) - 1);
		free(p);
	}
}

int			ft_bonus_helprec_3(char *arr)
{
	int		i;

	i = 0;
	while (arr[i] == '0' && arr[i] != '\0')
		i++;
	return (5001 - i);
}
