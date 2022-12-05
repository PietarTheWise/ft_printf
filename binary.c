/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoutere <pnoutere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:54:02 by pnoutere          #+#    #+#             */
/*   Updated: 2022/05/18 16:54:23 by pnoutere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*binary_helper(t_utils utils, va_list args, int size)
{
	if (size == 4)
	{
		utils._ulong_long = va_arg(args, unsigned long long);
		return (u_itoa_base(2, utils._ulong_long));
	}
	return (NULL);
}

char	*binary(t_utils utils, va_list args, int size)
{
	if (size == 0)
	{
		utils._uint = va_arg(args, unsigned int);
		return (u_itoa_base(2, utils._uint));
	}
	if (size == 1)
	{
		utils._ushort = va_arg(args, unsigned int);
		return (u_itoa_base(2, utils._ushort));
	}
	if (size == 2)
	{
		utils._uchar = va_arg(args, unsigned int);
		return (u_itoa_base(2, utils._uchar));
	}
	if (size == 3)
	{
		utils._ulong = va_arg(args, unsigned long);
		return (u_itoa_base(2, utils._ulong));
	}
	return (binary_helper(utils, args, size));
}
