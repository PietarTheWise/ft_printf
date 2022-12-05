/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_flag_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoutere <pnoutere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:19:40 by pnoutere          #+#    #+#             */
/*   Updated: 2022/05/18 17:12:40 by pnoutere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_precision(char *str, t_utils *utils, int *i)
{
	int	zeros;

	zeros = 0;
	if (str[0] == '.')
		utils->dot = 1;
	if (str[0] == '.' && ft_isdigit(str[1]))
	{
		if (str[1] == '0' && ft_isdigit(str[2]))
		{
			zeros = calc_zeros(str + 1);
			utils->precision = ft_atoi(str + 1 + zeros);
			if (!utils->precision)
				*i += zeros;
			else
				*i += (zeros + numlen(utils->precision));
		}
		else
		{
			utils->precision = ft_atoi(str + 1);
			*i += (zeros + numlen(utils->precision));
		}
		*i += 1;
	}
	else if (str[0] == '.' && !ft_isdigit(str[1]))
		*i += 1;
}

void	check_begin_flags_utils(char *str, t_utils *utils, int i)
{
	if (ft_isdigit(str[i]))
	{
		utils->padding = ft_atoi(str + i);
		check_precision(str + i + numlen(utils->padding), utils, &i);
		i += numlen(utils->padding);
	}
	else
	{
		check_precision(str + i, utils, &i);
	}
	utils->flag_len = i;
}

void	check_begin_flags(char *str, t_utils *utils)
{
	int	i;

	i = 0;
	while (str[i] == '0' || str[i] == ' ' || str[i] == '-'
		|| str[i] == '#' || str[i] == '+' || str[i] == '%')
	{
		if (str[i] == '0')
			utils->zero = 1;
		if (str[i] == ' ')
			utils->space = 1;
		if (str[i] == '-')
			utils->dash = 1;
		if (str[i] == '+')
			utils->plus = 1;
		if (str[i] == '#')
			utils->hashtag = 1;
		if (str[i] == '%')
			utils->percent = 1;
		i++;
	}
	check_begin_flags_utils(str, utils, i);
}

t_utils	*helpers_initiator(t_helpers *h, char *str)
{
	t_utils	*utils;

	h->count = read_args(str);
	h->i = 0;
	h->j = 0;
	h->ret_val = 0;
	utils = (t_utils *)malloc(sizeof(t_utils) * h->count);
	if (!utils)
		exit(1);
	return (utils);
}
