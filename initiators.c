/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoutere <pnoutere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 11:56:15 by pnoutere          #+#    #+#             */
/*   Updated: 2022/05/18 15:07:02 by pnoutere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	initiate_octet_helper(t_utils *utils)
{
	if ((utils->padding && utils->precision)
		&& (utils->padding == utils->precision))
	{
		utils->hashtag = 1;
	}
	else if (utils->padding < utils->precision)
	{
		utils->dash = 0;
	}
	else if ((utils->padding > utils->precision)
		&& (utils->padding && utils->precision))
		utils->zero = 0;
}

char	*initiate_octet(int size, t_utils *utils, va_list args)
{
	char	*ret;

	utils->space = 0;
	ret = octet_handler(size, args, *utils);
	if (ret[0] == '0' && ret[1] == '\0' && utils->dot)
	{
		free (ret);
		ret = ft_strnew(0);
		if (!utils->padding && utils->precision)
			return (ret);
	}
	initiate_octet_helper(utils);
	if (utils->hashtag && !(ft_strlen(ret) == 1 && ret[0] == '0'))
		ret = character_adder(&ret, "0");
	return (int_flag_adders(ret, *utils, 0));
}

char	*char_initiator(t_utils *utils, va_list args)
{
	char	*ret;

	ret = int_handler(5, args, *utils);
	if (ret[0] == 0)
	{
		utils->c = 1;
		utils->null = 1;
		utils->padding--;
		utils->char_flag = 1;
		utils->space = 0;
	}
	utils->zero = 0;
	utils->precision = 0;
	return (flag_adders(ret, *utils, 0));
}

char	*pointer_initiator(t_utils *utils, va_list args)
{
	char	*str;
	int		tmp;

	utils->space = 0;
	if (utils->dash)
		utils->space = 0;
	utils->hashtag = 1;
	str = ft_to_lowercase(x_handler(5, args, *utils));
	if (ft_strlen(str) == 1 && str[0] == '0' && utils->dot)
	{
		free(str);
		str = ft_strnew(0);
	}
	if (utils->precision > (int)ft_strlen(str))
	{
		tmp = utils->padding;
		utils->padding = 0;
		str = int_flag_adders(str, *utils, 1);
		str = character_adder(&str, "0x");
		utils->padding = tmp;
	}
	else
		str = character_adder(&str, "0x");
	str = int_flag_adders(str, *utils, 1);
	return (str);
}

void	utils_initiator(t_utils *utils)
{
	utils->null = 0;
	utils->c = 0;
	utils->x = 0;
	utils->str = 0;
	utils->char_flag = 0;
	utils->flag_len = 1;
	utils->sign = 1;
	utils->precision = 0;
	utils->plus = 0;
	utils->space = 0;
	utils->zero = 0;
	utils->dash = 0;
	utils->dot = 0;
	utils->percent = 0;
	utils->padding = 0;
	utils->padding_found = 0;
	utils->hashtag = 0;
	utils->octet = 0;
	utils->size = 0;
	utils->is_float = 0;
}
