/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orubin <orubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 20:25:59 by orubin            #+#    #+#             */
/*   Updated: 2020/04/13 12:30:37 by tasmity          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** moving through the array to the value of the fractional part
*/

void		ft_drob_f(char **drob, t_flag *mod)
{
	while (**drob != '.' && **drob != '\0')
		++(*drob);
	if (mod->zero == 5)
		return ;
	(*drob)++;
}

void		ft_out_sign(int sign, t_flag *mod)
{
	if (sign > 0)
		ft_putchar('-');
	else if (mod->flag[2] == '+')
		ft_putchar('+');
	else if (mod->flag[4] == ' ')
		ft_putchar(' ');
}

int			ft_bonus_helprec_2(char **res, int dt)
{
	(ft_posit(*res) > 0) ? (dt += ft_bonus_helprec_3(*res)) : (dt = 2);
	return (dt);
}

int			ft_prec(t_flag *mod, int *dt, int sign)
{
	if (mod->flag[3] != '-' && mod->flag[1] != '0')
	{
		(*dt + mod->prec >= mod->width) ? (*dt = mod->prec + *dt) :
		(*dt = ft_nbr_split(mod->width - *dt - mod->prec) +
			*dt + mod->prec);
	}
	ft_out_sign(sign, mod);
	if (mod->flag[1] == '0' && mod->flag[3] != '-')
	{
		(*dt + mod->prec >= mod->width) ? (*dt = mod->prec + *dt) :
		(*dt = ft_nbr_zero(mod->width - *dt - mod->prec) +
			*dt + mod->prec);
	}
	return (0);
}
