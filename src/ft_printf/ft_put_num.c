/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orubin <orubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 20:25:59 by orubin            #+#    #+#             */
/*   Updated: 2020/03/17 20:14:20 by orubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_print_num_d(intmax_t num)
{
	int			len;
	uintmax_t	u;

	len = 0;
	if (num < 0)
	{
		len++;
		u = -(uintmax_t)num;
	}
	else
		u = num;
	len += ft_putnum(u, 10, "0123456789");
	return (len);
}

int				ft_print_num_o(uintmax_t num)
{
	int			len;

	len = 0;
	len += ft_putnum(num, 8, "01234567");
	return (len);
}

int				ft_print_num_u(uintmax_t num)
{
	int			len;

	len = 0;
	len += ft_putnum(num, 10, "0123456789");
	return (len);
}

int				ft_print_num_x(uintmax_t num)
{
	int			len;

	len = 0;
	len += ft_putnum(num, 16, "0123456789abcdef");
	return (len);
}

int				ft_print_num_bigx(uintmax_t num)
{
	int			len;

	len = 0;
	len += ft_putnum(num, 16, "0123456789ABCDEF");
	return (len);
}
