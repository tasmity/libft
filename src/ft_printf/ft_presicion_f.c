/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_presicion_f.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orubin <orubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 20:25:59 by orubin            #+#    #+#             */
/*   Updated: 2020/05/30 23:26:59 by tasmity          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_helprec_1(char **drob, t_flag *mod, int *dt, char **res)
{
	char	*p;

	p = NULL;
	if (mod->zero != 5 && **drob != '\0'
		&& (int)ft_strlen(*drob) >= mod->prec
		&& (*drob)[mod->prec] >= '5' && ft_find_val(*drob, mod))
		*dt = 1;
	else if (mod->zero == 5 && **drob != '\0'
		&& (int)ft_strlen(*drob) >= mod->prec + 1
		&& (*drob)[mod->prec + 1] >= '5' && ft_find_val(*drob, mod))
		*dt = 1;
	if (**drob != '\0' && *dt)
		ft_bonus_helprec_1(p, mod, drob);
	if (!(*drob))
	{
		p = ft_strnew_float(ft_strlen(*res));
		p[ft_strlen(*res) - 1] = '1';
		*res = ft_sum(p, *res, (int)ft_strlen(*res) - 1);
		free(p);
	}
}

int			ft_helprec_2(char **drob, t_flag *mod, char **res)
{
	char	*p;
	int		dt;

	dt = 0;
	p = NULL;
	if (drob != NULL && *drob != NULL && **drob != '\0')
		ft_helpsub_f(drob, mod);
	if (drob != NULL && *drob != NULL && **drob != '\0' &&
		(mod->flag[0] == '#' || mod->prec > 0))
	{
		if (mod->prec > 0)
			ft_helpjoin_f(drob, mod);
		dt = 1;
	}
	ft_sum_1(drob, mod, res, p);
	return (ft_bonus_helprec_2(res, dt));
}

int			ft_helprec_3(char **drob, t_flag *mod, int *dt, char **res)
{
	int		hel;

	hel = 0;
	if (ft_posit(*res) <= 0 && mod->prec <= 0 && mod->flag[0] != '#')
		(*dt)--;
	if (mod->leng > 0 || mod->flag[2] == '+' || mod->flag[4] == ' ')
		++(*dt);
	if (drob != NULL && *drob != NULL && ft_posit(*res) >= 1 &&
		**drob == '\0' && (mod->prec > 0 || mod->flag[0] == '#'))
		++(*dt);
	if (*drob == NULL && mod->prec > 0)
	{
		hel = 1;
		++(*dt);
	}
	return (hel);
}

int			ft_helprec_4(char **drob, t_flag *mod, int *dt)
{
	if (drob && *drob && **drob != '\0')
	{
		if (mod->prec != 0)
			ft_put_float(*drob);
		else if (mod->flag[0] == '#')
			ft_putchar('.');
		if ((int)(ft_strlen(*drob) - 1) < mod->prec)
			ft_nbr_zero(mod->prec - (int)ft_strlen(*drob) + 1);
	}
	else if (mod->prec != 0 || mod->flag[0] != '\0')
	{
		ft_putchar('.');
		if (!(*drob) && mod->leng == 0)
			++(*dt);
		ft_nbr_zero(mod->prec);
	}
	ft_norm(dt, mod);
	return (*dt);
}

int			ft_prec_f(char *drob, t_flag *mod, char *res)
{
	int		dt;
	int		sign;

	sign = mod->leng;
	dt = 0;
	ft_drob_f(&drob, mod);
	ft_helprec_1(&drob, mod, &dt, &res);
	dt = ft_helprec_2(&drob, mod, &res);
	mod->leng = ft_helprec_3(&drob, mod, &dt, &res);
	ft_prec(mod, &dt, sign);
	ft_put_float(res);
	ft_helprec_4(&drob, mod, &dt);
	return (dt);
}
