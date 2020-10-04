/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_arifm_f.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orubin <orubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 20:25:59 by orubin            #+#    #+#             */
/*   Updated: 2020/05/23 16:21:42 by tasmity          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_posit(char *arr)
{
	int			i;
	int			j;

	i = 0;
	j = 5000;
	while (arr[i] == '0' && arr[i] != '\0')
		i++;
	while (arr[j] == '0' && j > 0)
		j--;
	if (j < 0)
		return (0);
	return (j - i + 1);
}

/*
** raising the fractional part of a number to the power of five
*/

char			*ft_mult_five(int power, int k, char *res, int max)
{
	intmax_t	proizv;
	intmax_t	ost;
	int			count;
	int			i;

	i = 0;
	count = 0;
	ost = 0;
	res[k - max + power] = '1';
	while (count < power)
	{
		proizv = 5 * (res[k - i - max + power] - '0') + ost;
		ost = 0;
		if (proizv >= 10)
			ost = proizv / 10;
		proizv = proizv % 10;
		res[k - i - max + power] = proizv + '0';
		if (proizv == 0 && ost == 0 && ft_posit(res) < i)
		{
			i = -1;
			count++;
		}
		i++;
	}
	return (res);
}

/*
** raising an integer part of a number to the power of two
*/

char			*ft_mult_two(int power, int k, char *res)
{
	intmax_t	proizv;
	intmax_t	ost;
	int			count;
	int			i;

	i = 0;
	count = 0;
	ost = 0;
	res[k] = '1';
	while (count < power)
	{
		proizv = 2 * (res[k - i] - '0') + ost;
		ost = 0;
		if (proizv >= 10)
			ost = proizv / 10;
		proizv = proizv % 10;
		res[k - i] = proizv + '0';
		if (proizv == 0 && ost == 0 && ft_posit(res) < i)
		{
			i = -1;
			count++;
		}
		i++;
	}
	return (res);
}

/*
** adding the value of the current bit to the intermediate result
*/

char			*ft_sum(char *exp_five, char *sum_one, int size)
{
	int			ost;
	int			res;
	int			i;

	i = -1;
	ost = 0;
	while (++i < size + 1)
	{
		res = ((exp_five[size - i] - '0') + (sum_one[size - i] - '0') + ost);
		ost = 0;
		if (res >= 10)
			ost = res / 10;
		res %= 10;
		sum_one[size - i] = res + '0';
	}
	if (ost != 0)
		return (NULL);
	return (sum_one);
}

int				ft_put_float(char *str)
{
	int			i;

	i = 0;
	while (*str == '0')
		str++;
	if (*str == '\0')
		ft_putchar('0');
	while (*str)
	{
		i++;
		ft_putchar(*str);
		str++;
	}
	return (i);
}
