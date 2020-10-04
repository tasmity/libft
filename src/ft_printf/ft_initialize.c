/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orubin <orubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 20:25:59 by orubin            #+#    #+#             */
/*   Updated: 2020/03/17 20:14:20 by orubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** We initialize structure fields.
** Width is zero.
** Precision is -1. It means we don't have dot here.
** Length is '\0'
** Specifier is '\0'
** Zero fill flags.
*/

void		ft_initialize(t_flag *mod)
{
	mod->width = 0;
	mod->prec = -1;
	mod->leng = '\0';
	mod->spec = '\0';
	mod->zero = -1;
	ft_bzero(mod->flag, 5);
}

/*
** If we've found l, checking for ll
*/

void		ft_for_l(char *tmp, int count, t_flag *mod)
{
	if (tmp[count + 1] == 'l')
		mod->leng = 'K';
	else
		mod->leng = 'l';
}

/*
** If we've found h, checking for hh
*/

void		ft_for_h(char *tmp, int count, t_flag *mod)
{
	if (tmp[count + 1] == 'h')
		mod->leng = 'H';
	else
		mod->leng = 'h';
}

/*
** Zero fill flags
*/

void		ft_off_zero(t_flag *mod)
{
	mod->flag[3] ? mod->flag[1] = '\0' : 0;
	mod->prec < 0 ? mod->prec = -1 : 0;
	if (mod->prec != -1)
		if (mod->spec == 'd' || mod->spec == 'i' || mod->spec == 'o' ||
			mod->spec == 'x' || mod->spec == 'X' || mod->spec == 'u' ||
			mod->spec == 'U')
			mod->flag[1] = '\0';
}
