/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoutere <pnoutere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 13:48:08 by pnoutere          #+#    #+#             */
/*   Updated: 2022/05/17 11:40:01 by pnoutere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check_definer_helper(char *str, int size, t_utils *utils, va_list args)
{
	char	*ret;

	if (str[0] == '%')
	{
		ret = ft_memset(ft_strnew(1), '%', 1);
		return (ret);
	}
	if (str[0] == 'd' || str[0] == 'i')
	{
		str = int_handler(size, args, *utils);
		if (utils->dot && str[0] == '0' && !utils->precision)
		{
			if (utils->dash)
				utils->zero = 0;
			utils->plus = 0;
			free(str);
			str = ft_strnew(0);
		}
		str = int_flag_adders(str, *utils, 0);
		return (str);
	}
	if (str[0] == '\0')
		return (0);
	utils->flag_len++;
	return (check_definer(str + 1, size, utils, args));
}

char	*utils_uint(int size, t_utils *utils, va_list args)
{
	char	*ret;

	utils->space = 0;
	ret = u_handler(size, args, *utils);
	if (ret[0] == '0' && utils->dot && !utils->precision)
	{
		free(ret);
		ret = ft_strnew(0);
		return (int_flag_adders(ret, *utils, 0));
	}
	return (int_flag_adders(ret, *utils, 0));
}

char	*check_definer(char *str, int size, t_utils *utils, va_list args)
{
	if (str[0] == 'o' || str[0] == 'u')
		utils->plus = 0;
	if (str[0] == 'o')
		return (initiate_octet(size, utils, args));
	if (str[0] == 'u')
		return (utils_uint(size, utils, args));
	if (str[0] == 'x')
		return (ft_to_lowercase(x_handler(size, args, *utils)));
	if (str[0] == 'X')
		return (x_handler(size, args, *utils));
	if (str[0] == 'f')
		return (f_handler(args, *utils, size));
	if (str[0] == 'c')
		return (char_initiator(utils, args));
	if (str[0] == 's')
	{
		utils->plus = 0;
		utils->zero = 0;
		return (string_handler(args, *utils));
	}
	if (str[0] == 'p')
		return (pointer_initiator(utils, args));
	if (str[0] == 'b')
		return (binary(*utils, args, size));
	return (check_definer_helper(str, size, utils, args));
}

char	*analyze(char *str, int start, va_list args, t_utils *utils)
{
	start++;
	utils->flag_len += 2;
	if (str[start] == 'l' && str[start + 1] == 'l')
	{
		utils->flag_len += 1;
		return (check_definer(str + start + 2, 4, utils, args));
	}
	if (str[start] == 'l' && str[start + 1] != 'l')
		return (check_definer(str + start + 1, 3, utils, args));
	if (str[start] == 'h' && str[start + 1] == 'h')
	{
		utils->flag_len += 1;
		return (check_definer(str + start + 2, 2, utils, args));
	}
	if (str[start] == 'h' && str[start + 1] != 'h')
		return (check_definer(str + start + 1, 1, utils, args));
	if (str[start] == 'L')
		return (check_definer(str + start + 1, 1, utils, args));
	utils->flag_len -= 1;
	return (check_definer(str + start, 0, utils, args));
}

int	check_nums(long long nb, int base, char **str)
{
	if (base == 10 && nb < -9223372036854775807)
	{
		*str = ft_strnew(20);
		*str = ft_strcpy(*str, "-9223372036854775808");
		return (1);
	}
	return (0);
}
