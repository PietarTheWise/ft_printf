/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoutere <pnoutere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:32:09 by pietar            #+#    #+#             */
/*   Updated: 2022/05/18 18:24:21 by pnoutere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <strings.h>
# include "libft/libft.h"

typedef struct s_utils
{
	int					octet;
	int					c;
	int					x;
	int					str;
	int					null;
	int					char_flag;
	int					hashtag;
	int					dash;
	int					plus;
	int					space;
	int					zero;
	int					size;
	int					dot;
	int					padding;
	int					sign;
	int					flag_len;
	int					precision;
	int					percent;
	int					padding_found;
	int					is_float;
	char				_char;
	int					_int;
	short				_short;
	long				_long;
	long long			_long_long;
	unsigned char		_uchar;
	unsigned int		_uint;
	unsigned short		_ushort;
	unsigned long		_ulong;
	unsigned long long	_ulong_long;
	double				_double;
	long double			_long_double;
	char				*result;
}				t_utils;

typedef struct s_helpers
{
	int			i;
	int			j;
	int			percent;
	int			count;
	int			ret_val;
	char		*res;
}				t_helpers;

typedef unsigned long long	t_ull;

typedef union u_ldouble_cast {
	long double	f;
	struct {
		t_ull	mantissa : 63;
		t_ull	int_part : 1;
		t_ull	exponent : 15;
		t_ull	sign : 1;
	} s_parts;
}	t_ldouble_cast;

int			ftoa(int prec, long double nb);
char		*itoa_base(int base, long long nb);
char		*ft_to_lowercase(char *str);
char		*ft_ftoa(long double f, t_utils utils, t_ldouble_cast un);
char		*flag_adders(char *str, t_utils utils, int len);
char		*check_definer_int(char ch, int size, t_utils utils, va_list args);
char		*check_definer(char *str, int size, t_utils *utils, va_list args);
char		*int_handler(int size, va_list args, t_utils utils);
long long	ft_absolute(long long int n);
void		ft_swap(char *a, char *b);
char		*ft_to_lowercase(char *str);
int			numlen(long long n);
int			check_nums(long long nb, int base, char **str);
int			read_args(char *str);
char		*check_helper(t_utils utils, int sign, char *str);
char		*x_handler(int size, va_list args, t_utils utils);
char		*f_handler(va_list args, t_utils utils, int size);
char		*character_adder(char **str, char *add);
char		*analyze(char *str, int start, va_list args, t_utils *utils);
char		*octet_handler(int size, va_list args, t_utils utils);
char		*u_handler(int size, va_list args, t_utils utils);
char		*string_handler(va_list args, t_utils utils);
void		string_realloc(char **str, int *length);
char		*int_flag_adders(char *str, t_utils utils, int len);
char		*int_adder_utils(char *str, char *add, t_utils utils);
char		*char_initiator(t_utils *utils, va_list args);
char		*initiate_octet(int size, t_utils *utils, va_list args);
char		*pointer_initiator(t_utils *utils, va_list args);
t_utils		*helpers_initiator(t_helpers *h, char *str);
int			calc_zeros(char *str);
int			ft_printf(char *str, ...);
void		utils_initiator(t_utils *utils);
void		check_begin_flags(char *str, t_utils *utils);
char		*flag_adders(char *str, t_utils utils, int len);
char		*str_maker(char *str);
char		*u_itoa_base(int base, unsigned long long nb);
void		stringify_float(char *float_nums, int precision);
char		*binary(t_utils utils, va_list args, int size);
void		check_color(char *str, int *i);
void		print_results(t_helpers *h, char **end_str, t_utils *utils);
void		rounding(char *float_nums);
char		*check_effects(char *str, int *i);
void		find_second_nb(long double f, t_utils *utils);
int			ftoa_loop(long double f, int precision, char *after_dot);
#endif
