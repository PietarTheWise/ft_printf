/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoutere <pnoutere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 13:37:58 by pnoutere          #+#    #+#             */
/*   Updated: 2022/05/16 18:09:54 by pnoutere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*octet_helper(int size, va_list args, t_utils utils)
{
	if (size == 4)
	{
		utils._ulong_long = va_arg(args, unsigned long long);
		return (u_itoa_base(8, utils._ulong_long));
	}
	return (NULL);
}

char	*octet_handler(int size, va_list args, t_utils utils)
{
	if (size == 0)
	{
		utils._uint = va_arg(args, unsigned int);
		return (u_itoa_base(8, utils._uint));
	}
	if (size == 1)
	{
		utils._ushort = va_arg(args, unsigned int);
		return (u_itoa_base(8, utils._ushort));
	}
	if (size == 2)
	{
		utils._uchar = va_arg(args, unsigned int);
		return (u_itoa_base(8, utils._uchar));
	}
	if (size == 3)
	{
		utils._ulong = va_arg(args, unsigned long);
		return (u_itoa_base(8, utils._ulong));
	}
	return (octet_helper(size, args, utils));
}

char	*u_helper(int size, va_list args, t_utils utils)
{
	if (size == 4)
	{
		utils._ulong_long = va_arg(args, unsigned long long);
		return (u_itoa_base(10, utils._ulong_long));
	}
	return (NULL);
}

char	*u_handler(int size, va_list args, t_utils utils)
{
	if (size == 0)
	{
		utils._uint = va_arg(args, unsigned int);
		return (u_itoa_base(10, utils._uint));
	}
	if (size == 1)
	{
		utils._ushort = va_arg(args, unsigned int);
		return (u_itoa_base(10, utils._ushort));
	}
	if (size == 2)
	{
		utils._uchar = va_arg(args, unsigned int);
		return (u_itoa_base(10, utils._uchar));
	}
	if (size == 3)
	{
		utils._ulong = va_arg(args, unsigned long);
		return (u_itoa_base(10, utils._ulong));
	}
	return (u_helper(size, args, utils));
}

char	*check_definer_int(char ch, int size, t_utils utils, va_list args)
{
	char	*str;

	if (ch == 'd' || ch == 'i')
	{
		str = int_handler(size, args, utils);
		if (utils.dot && str[0] == '0' && !utils.precision)
		{
			if (utils.dash)
				utils.zero = 0;
			utils.plus = 0;
			str = ft_strnew(0);
		}
		str = int_flag_adders(str, utils, 0);
		return (str);
	}
	return (0);
}
