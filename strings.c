/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoutere <pnoutere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:04:50 by pnoutere          #+#    #+#             */
/*   Updated: 2022/05/18 17:35:31 by pnoutere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	string_handler_util(char **str, t_utils *utils, int *flag)
{
	*flag = 0;
	if (!(*str))
	{
		*str = ft_strnew(ft_strlen("(null)"));
		ft_strcpy(*str, "(null)");
		*flag = 1;
	}
	if (!(*str) || (utils->dot && !utils->precision))
	{
		*str = ft_strnew(0);
		*flag = 1;
	}
	else if (utils->dot && utils->padding > (int)ft_strlen(*str))
	{
		if (!utils->precision)
		{
			if (*flag)
				free(*str);
			*str = ft_strnew(0);
			*flag = 1;
		}
	}
	if ((int)ft_strlen(*str) <= utils->precision)
		utils->precision = 0;
}

char	*string_handler(va_list args, t_utils utils)
{
	char	*str;
	char	*str_prec;
	int		flag;

	flag = 0;
	str = va_arg(args, char *);
	string_handler_util(&str, &utils, &flag);
	if (str[0] == '\0')
		utils.precision = 0;
	if (utils.precision)
	{
		str_prec = ft_strnew(utils.precision);
		ft_bzero(str_prec, utils.precision);
		str_prec = ft_strncpy(str_prec, str, utils.precision);
		str = str_prec;
		return (int_flag_adders(str, utils, 0));
	}
	str_prec = ft_strnew(ft_strlen(str));
	str_prec = ft_strcpy(str_prec, str);
	if (flag)
		free(str);
	utils.is_float = 1;
	return (int_flag_adders(str_prec, utils, 0));
}

char	*str_maker(char *str)
{
	char	*ret;

	ret = ft_strnew(ft_strlen(str + 1));
	ret = ft_strcpy(ret, str + 1);
	free(str);
	return (ret);
}

void	print_results(t_helpers *h, char **end_str, t_utils *utils)
{
	if (!ft_strcmp("%", h->res))
	{
		*end_str = flag_adders(h->res, *utils, 0);
		ft_putstr(*end_str);
		h->res = *end_str;
	}
	else
	{
		if (utils->null)
			ft_putstr_null(h->res);
		else
			ft_putstr(h->res);
	}
}
