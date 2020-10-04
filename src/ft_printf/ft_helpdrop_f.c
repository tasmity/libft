/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpdrop_f.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orubin <orubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 20:25:59 by orubin            #+#    #+#             */
/*   Updated: 2020/05/23 20:28:09 by tasmity          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_helpsub_f(char **drob, t_flag *mod)
{
	char	*tmp;

	if (mod->zero != 5)
		(mod->prec > 0) ? (tmp = ft_strsub_float(*drob, 0, mod->prec)) :
			(tmp = ft_strsub_float(*drob, 0, 1));
	else
		tmp = ft_strsub_float(*drob, 1, mod->prec);
	ft_strcpy_f(*drob, tmp);
	free(tmp);
}

void		ft_helpjoin_f(char **drob, t_flag *mod)
{
	char	*tmp;
	char	*p;

	if (mod->zero == 5)
		p = ft_strsub_float(*drob, 0, ft_strlen(*drob));
	else if (mod->zero == 0)
		p = ft_strdup("0");
	else
		p = ft_strsub_float(*drob, 0, ft_strlen(*drob) - 1);
	tmp = ft_strjoin(".", p);
	ft_strcpy_f(*drob, tmp);
	free(tmp);
	free(p);
}

char		*ft_strsub_float(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	if (!(str = ft_strnew_float(len)))
		return (NULL);
	while (len-- && s[start] != '\0')
	{
		str[i++] = s[start++];
	}
	return (str);
}

void		ft_check_drob(long double nbr, t_flag *mod)
{
	int		count;

	count = 0;
	if (nbr < 0)
		nbr *= -1;
	if (nbr == (uintmax_t)nbr)
	{
		mod->zero = 0;
		return ;
	}
	if (nbr < 1)
		nbr += 1;
	while (nbr != (uintmax_t)nbr && (int)nbr != 0)
	{
		nbr -= (uintmax_t)nbr;
		nbr *= 10;
		count++;
		if (count > 10000)
			return ;
	}
	if ((uintmax_t)nbr == 5)
		mod->zero = 5;
}
