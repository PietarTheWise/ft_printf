/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoutere <pnoutere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:49:23 by pietar            #+#    #+#             */
/*   Updated: 2022/05/18 17:13:55 by pnoutere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	scrutinize(t_utils *utils, t_helpers *h, char *str, va_list args)
{
	char	*end_str;

	if (utils->percent)
	{
		ft_putchar('%');
		h->i += utils->flag_len + 1;
		h->ret_val++;
	}
	else
	{
		h->res = analyze(str, h->i + utils->flag_len, args, utils);
		if (h->res)
		{
			print_results(h, &end_str, utils);
			h->ret_val += ft_strlen(h->res) + utils->char_flag;
			free(h->res);
			h->i += (utils->flag_len + 1);
		}
		else
		{
			free(h->res);
			h->i += utils->flag_len;
		}
	}
}

static int	check_double_percent(t_helpers *h, char *str)
{
	if (str[h->i + 1] == '%')
	{
		ft_putchar('%');
		h->i += 2;
		h->ret_val++;
		return (1);
	}
	return (0);
}

static void	start_process(t_helpers	*h, t_utils utils, char *str, va_list args)
{
	utils_initiator(&utils);
	check_begin_flags(str + 1 + h->i, &utils);
	scrutinize(&utils, h, str, args);
	h->percent = utils.percent;
	h->j++;
}

static int	printf_return(int ret, t_utils **utils)
{
	free(*utils);
	return (ret);
}

int	ft_printf(char *str, ...)
{
	va_list		args;
	t_utils		*utils;
	t_helpers	h;

	va_start(args, str);
	utils = helpers_initiator(&h, str);
	while (str[h.i])
	{
		check_color(str, &h.i);
		if (str[h.i] == '%')
		{
			if (check_double_percent(&h, str))
				continue ;
			start_process(&h, utils[h.j], str, args);
		}
		if (str[h.i] == '\0')
			return (printf_return(h.ret_val, &utils));
		if (str[h.i] == '%' && !h.percent)
			continue ;
		ft_putchar(str[h.i]);
		h.i++;
		h.ret_val++;
	}
	return (printf_return(h.ret_val, &utils));
}
