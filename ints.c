/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ints.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoutere <pnoutere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:13:12 by pnoutere          #+#    #+#             */
/*   Updated: 2022/05/18 17:35:21 by pnoutere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*int_handler_help(int size, va_list args, t_utils utils)
{
	char	*str;

	if (size == 4)
	{
		utils._long_long = va_arg(args, long long);
		return (itoa_base(10, utils._long_long));
	}
	if (size == 5)
	{
		utils._char = (char)va_arg(args, int);
		str = ft_strnew(1);
		str[0] = utils._char;
		return (str);
	}
	return (NULL);
}

char	*int_handler(int size, va_list args, t_utils utils)
{
	if (size == 0)
	{
		utils._int = va_arg(args, int);
		return (itoa_base(10, utils._int));
	}
	if (size == 1)
	{
		utils._short = va_arg(args, int);
		return (itoa_base(10, utils._short));
	}
	if (size == 2)
	{
		utils._int = (char)va_arg(args, int);
		return (itoa_base(10, utils._int));
	}
	if (size == 3)
	{
		utils._long = va_arg(args, long);
		return (itoa_base(10, utils._long));
	}
	return (int_handler_help(size, args, utils));
}

char	*int_adder_utils(char *str, char *add, t_utils utils)
{
	char	*temp;

	if (utils.sign > 0 && utils.plus && add[0] != '0')
		str = character_adder(&str, "+");
	if (utils.sign < 0 && add[0] != '0')
		str = character_adder(&str, "-");
	if (utils.space && (str[0] != '-' && str[0] != '+') && !utils.zero)
		str = character_adder(&str, " ");
	if (utils.dash)
	{
		temp = str;
		str = ft_strjoin(temp, add);
		free(temp);
	}
	else
		str = character_adder(&str, add);
	if (utils.sign > 0 && utils.plus && add[0] == '0')
		str = character_adder(&str, "+");
	if (utils.sign < 0 && add[0] == '0')
		str = character_adder(&str, "-");
	if (utils.space && (str[0] != '-' && str[0] != '+') && utils.zero)
		str = character_adder(&str, " ");
	free (add);
	return (str);
}

void	int_flag_adder_ifs(int *len, t_utils *utils, char *ch, char **add)
{
	if (utils->sign < 0 || (utils->plus && utils->sign > 0))
		*len -= 1;
	if (utils->space && utils->sign > 0)
		*len -= 1;
	if (utils->plus && utils->sign > 0 && !utils->zero)
		*len += 1;
	if (utils->plus && utils->sign > 0 && !utils->space && !utils->zero)
		*len -= 1;
	if (*len < 0)
		*len = 0;
	if (utils->zero && !utils->dash
		&& ((utils->padding <= utils->precision
				|| !utils->precision) || (utils->is_float)))
	{
		*ch = '0';
	}
	*add = ft_strnew(*len);
	ft_memset(*add, *ch, *len);
}

char	*int_flag_adders(char *str, t_utils utils, int len)
{
	char	*temp;
	char	*add;
	char	ch;

	ch = ' ';
	temp = str;
	if (str[0] == '-')
	{
		utils.sign = -1;
		str += 1;
	}
	len = utils.precision - ft_strlen(str);
	if (len < 0)
		len = 0;
	add = ft_strnew(len);
	ft_memset(add, '0', len);
	str = ft_strjoin(add, str);
	free (temp);
	free (add);
	len = utils.padding - ft_strlen(str);
	int_flag_adder_ifs(&len, &utils, &ch, &add);
	return (int_adder_utils(str, add, utils));
}
