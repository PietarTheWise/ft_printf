/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoutere <pnoutere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 13:04:43 by pnoutere          #+#    #+#             */
/*   Updated: 2022/05/16 18:09:40 by pnoutere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*x_handler_utils(int size, va_list args, t_utils utils, char *str)
{
	if (size == 0)
	{
		utils._uint = va_arg(args, unsigned int);
		str = itoa_base(16, utils._uint);
	}
	if (size == 1)
	{
		utils._ushort = va_arg(args, unsigned int);
		str = u_itoa_base(16, utils._ushort);
	}
	if (size == 2)
	{
		utils._uchar = va_arg(args, unsigned int);
		str = u_itoa_base(16, utils._uchar);
	}
	return (str);
}

static void	x_handler_result_help(char **str, t_utils utils)
{
	int	tmp;

	tmp = utils.padding;
	if (utils.padding && utils.zero && !utils.precision)
	{
		utils.padding -= 2;
		*str = int_flag_adders(*str, utils, 0);
		*str = character_adder(str, "0X");
	}
	else
	{
		tmp = utils.padding;
		utils.padding = 0;
		*str = int_flag_adders(*str, utils, 0);
		*str = character_adder(str, "0X");
		utils.padding = tmp;
		utils.precision = 0;
		utils.zero = 0;
		*str = int_flag_adders(*str, utils, 0);
	}
}

static void	x_handler_result_util(char **str, t_utils utils)
{
	int	tmp;

	if (utils.precision > (int)ft_strlen(*str))
	{
		tmp = utils.padding;
		utils.padding = 0;
		*str = int_flag_adders(*str, utils, 1);
		*str = character_adder(str, "0X");
		utils.padding = tmp;
	}
	else
		*str = character_adder(str, "0X");
	*str = int_flag_adders(*str, utils, 0);
}

char	*x_handler_end_result(t_utils utils, char *str)
{
	utils.space = 0;
	if (utils.dot && str[0] == '0' && !utils.precision)
	{
		free(str);
		str = ft_strnew(0);
		str = int_flag_adders(str, utils, 0);
		return (str);
	}
	else if (!ft_strcmp("0", str))
		utils.hashtag = 0;
	if (utils.hashtag)
	{
		if (utils.zero && utils.padding > ((int)ft_strlen(str) + 2))
			x_handler_result_help(&str, utils);
		else
			x_handler_result_util(&str, utils);
	}
	else
		str = int_flag_adders(str, utils, 0);
	return (str);
}

char	*x_handler(int size, va_list args, t_utils utils)
{
	char	*str;

	utils.plus = 0;
	if (size <= 2)
	{
		str = x_handler_utils(size, args, utils, NULL);
	}
	if (size == 3)
	{
		utils._ulong = va_arg(args, unsigned long);
		str = u_itoa_base(16, utils._ulong);
	}
	if (size == 4)
	{
		utils._ulong_long = va_arg(args, unsigned long long);
		str = u_itoa_base(16, utils._ulong_long);
	}
	if (size == 5)
	{
		str = u_itoa_base(16,
				(unsigned long long)va_arg(args, unsigned long long));
		return (str);
	}
	return (x_handler_end_result(utils, str));
}
