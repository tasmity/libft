/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orubin <orubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 20:25:59 by orubin            #+#    #+#             */
/*   Updated: 2020/07/10 19:50:36 by tasmity          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include "libft.h"

# define CR  "\x1B[0m"
# define RED  "\x1B[31m"
# define GREEN  "\x1B[32m"
# define YELLOW  "\x1B[33m"
# define BLUE  "\x1B[34m"
# define MAGENTA  "\x1B[35m"
# define CYAN  "\x1B[36m"
# define WHITE  "\x1B[37m"

/*
** spec: d, i, u, p, x, X, o, f, s, c, %, C, S, U
** flag: -, +, #, 0, ' '
** width: *, (num)
** prec: .(num), .*
** leng: (none), hh, h, l, ll, L, j, z, t
*/

/*
** char		flag[5];	[0] > #, [1] > 0, [2] > +, [3] > -, [4] > ' '
*/

typedef struct		s_flag
{
	char			flag[5];
	int				width;
	int				prec;
	char			spec;
	char			leng;
	int				zero;
}					t_flag;

typedef struct		s_float
{
	uintmax_t		mantisa : 64;
	unsigned int	exponent : 15;
	short int		sign : 1;
}					t_float;

typedef union		u_float
{
	long double		f;
	t_float			bytes;
}					t_float_u;

int					ft_printf(const char *format, ...);
int					ft_read_flag(va_list ap, const char **format);
int					ft_leng(char c);
char				*ft_cut(const char **format);
/*
** Zeroing structure
*/
void				ft_initialize(t_flag *mod);
/*
** Filling structure
*/
void				ft_attribut(t_flag *mod, char **tmp, int len, va_list ap);
/*
** Filling length
*/
void				ft_for_l(char *tmp, int count, t_flag *mod);
void				ft_for_h(char *tmp, int count, t_flag *mod);
/*
** Filling specifier
*/
void				ft_for_spec(char *format, t_flag *mod, int len);
/*
** Filling flags
*/
int					ft_for_flag(char **format, t_flag *mod);
void				ft_off_zero(t_flag *mod);
/*
** Filling width
*/
int					ft_for_width(char *format, t_flag *mod, va_list ap);
/*
** Filling precision
*/
int					ft_for_prec(char *format, t_flag *mod, va_list ap);
/*
** Filling leng modifier
*/
int					ft_for_leng(char *format, t_flag *mod);
/*
** Output, depens on data type
*/
int					ft_print_all(va_list ap, t_flag *mod);
/*
** %s output
*/
int					ft_print_s(va_list ap, t_flag *mod);
int					ft_print_split(t_flag *mod, size_t size, char *str);
int					ft_print_prec(t_flag *mod, size_t size, char *str);
int					ft_split_second(t_flag *mod, size_t size, char *str);
int					ft_split_first(t_flag *mod, size_t size, char *str);
/*
** %cC output
*/
int					ft_print_c(va_list ap, t_flag *mod);
int					ft_print_ano(t_flag *mod);
/*
** Auxilary fucntions for digits
*/
int					ft_len_nbr(t_flag *mod, intmax_t nbr);
int					ft_nbr_split(int split);
int					ft_nbr_zero(int zero);
/*
** %di output
*/
int					ft_print_d(va_list ap, t_flag *mod);
int					ft_putnbr_all(intmax_t nbr, t_flag *mod);
void				ft_print_sign(intmax_t nbr, t_flag *mod);
int					ft_get_zero(t_flag *mod, int *len, int sign);
int					ft_get_split(t_flag *mod, int *len);
int					ft_putnum(uintmax_t n, unsigned int base,
						const char *digits);
int					ft_print_num_d(intmax_t num);
int					ft_print_num_o(uintmax_t num);
int					ft_print_num_u(uintmax_t num);
int					ft_print_num_x(uintmax_t num);
int					ft_print_num_bigx(uintmax_t num);
int					ft_print_num(t_flag *mod, intmax_t num);
int					ft_putlen(uintmax_t n, unsigned int base);
/*
** %xX %o %uU output
*/
int					ft_print_u(va_list ap, t_flag *mod);
int					ft_unsigned_u(uintmax_t nbr, t_flag *mod);
void				ft_print_pref(t_flag *mod, uintmax_t nbr);
int					ft_put_sign(t_flag *mod, uintmax_t nbr);
int					ft_put_mnum(t_flag *mod, int len, int *zero, int *split);
/*
** %f output
*/
int					ft_print_f(va_list ap, t_flag *mod);
int					ft_double_f(long double nbr, t_flag *mod);
int					ft_out_nan(t_flag *mod, char *arr);
char				*ft_inf_nan(int cho, long double nbr);
char				*ft_strnew_float(size_t size);
void				ft_install(int *power, char **drob, char **ot, int k);
int					ft_help_f(int k, t_float_u flo, t_flag *mod);
int					ft_posit(char *arr);
char				*ft_mult_two(int power, int k, char *res);
char				*ft_sum(char *exp_five, char *sum_one, int size);
void				ft_sum_1(char **drob, t_flag *mod, char **res, char *p);
int					ft_long_arifm_ot(char *ot, char *drob, int power,
					t_flag *mod);
int					ft_long_arifm_drob(char *drob, t_flag *mod, char *res);
char				*ft_mult_five(int power, int k, char *res, int max);
int					ft_find_max(char *arr);
int					ft_prec_f(char *drob, t_flag *mod, char *res);
void				ft_drob_f(char **drob, t_flag *mod);
void				ft_norm(int *dt, t_flag *mod);
void				ft_out_sign(int sign, t_flag *mod);
int					ft_prec(t_flag *mod, int *dt, int sign);
int					ft_find_val(char *drob, t_flag *mod);
int					ft_put_float(char *str);
int					ft_bonus_helprec_1(char *p, t_flag *mod, char **drob);
int					ft_bonus_helprec_2(char **res, int dt);
int					ft_bonus_helprec_3(char *arr);
void				ft_helprec_1(char **drob, t_flag *mod, int *dt, char **res);
int					ft_helprec_2(char **drob, t_flag *mod, char **res);
int					ft_helprec_3(char **drob, t_flag *mod, int *dt, char **res);
int					ft_helprec_4(char **drob, t_flag *mod, int *dt);
int					ft_print_error(const char *format);
char				*ft_strcpy_f(char *dst, char *src);
int					ft_read(va_list ap, const char *format);
void				ft_helpsub_f(char **drob, t_flag *mod);
void				ft_helpjoin_f(char **drob, t_flag *mod);
char				*ft_strsub_float(char const *s, unsigned int start,
					size_t len);
void				ft_check_drob(long double nbr, t_flag *mod);

#endif
