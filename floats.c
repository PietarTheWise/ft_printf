/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoutere <pnoutere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 09:43:04 by gmolin            #+#    #+#             */
/*   Updated: 2022/05/18 15:07:18 by pnoutere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*f_handler_util(va_list args, t_utils utils, char *str)
{
	t_ldouble_cast	un;

	utils._double = va_arg(args, double);
	un.f = (long double)utils._double;
	str = ft_ftoa((long double)utils._double, utils, un);
	str = int_flag_adders(str, utils, 0);
	return (str);
}

char	*f_handler(va_list args, t_utils utils, int size)
{
	char			*str;
	t_ldouble_cast	un;

	str = NULL;
	utils.is_float = 1;
	if (!utils.precision && !utils.dot)
		utils.precision = 6;
	if (size == 3)
		size = 0;
	if (size == 0)
	{
		str = f_handler_util(args, utils, str);
		return (str);
	}
	if (size == 1)
	{
		utils._long_double = va_arg(args, long double);
		un.f = utils._long_double;
		str = ft_ftoa(utils._long_double, utils, un);
		str = int_flag_adders(str, utils, 0);
		return (str);
	}
	return (NULL);
}

void	stringify_float(char *float_nums, int precision)
{
	static int	flag;

	if (precision == 0)
	{
		flag = 0;
		return ;
	}
	if (float_nums[precision] > '9' && flag == 1)
	{
		float_nums[precision] = '0';
		float_nums[precision - 1] += 1;
	}
	if (float_nums[precision] >= '5' && !flag)
	{
		float_nums[precision] = '0';
		float_nums[precision - 1] += 1;
		flag = 1;
	}
	if (!flag && float_nums[precision] < '5')
		return ;
	stringify_float(float_nums, precision - 1);
}
