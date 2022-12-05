/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonuses.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoutere <pnoutere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 10:08:07 by pnoutere          #+#    #+#             */
/*   Updated: 2022/05/18 16:55:48 by pnoutere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*return_str(char *str, char *in_str, int *i)
{
	*i += (int)ft_strlen(in_str);
	return (str);
}

char	*check_effects(char *str, int *i)
{
	if (!strncmp(str + *i, "{regular}", 9))
		return (return_str("m", "{regular}", i));
	else if (!strncmp(str + *i, "{bold}", 6))
		return (return_str(";1m", "{bold}", i));
	else if (!strncmp(str + *i, "{faded}", 7))
		return (return_str(";2m", "{faded}", i));
	else if (!strncmp(str + *i, "{italic}", 8))
		return (return_str(";3m", "{italic}", i));
	else if (!strncmp(str + *i, "{underline}", 11))
		return (return_str(";4m", "{underline}", i));
	else if (!strncmp(str + *i, "{blink}", 7))
		return (return_str(";5m", "{blink}", i));
	else if (!strncmp(str + *i, "{negative}", 10))
		return (return_str(";7m", "{negative}", i));
	return (return_str("m", "", i));
}

static void	put_color(char *str, char *in_str, int *i, int len)
{
	ft_putstr(str);
	*i += len;
	if (ft_strncmp("m\033[0m", str, 8))
		ft_putstr(check_effects(in_str, i));
}

void	check_color(char *str, int *i)
{
	if (str[*i] == '{')
	{
		if (!strncmp(str + *i, "{cyan}", 6))
			put_color("\033[36", str, i, 6);
		else if (!strncmp(str + *i, "{white}", 7))
			put_color("\033[37", str, i, 7);
		else if (!strncmp(str + *i, "{red}", 5))
			put_color("\033[31", str, i, 5);
		else if (!strncmp(str + *i, "{blue}", 6))
			put_color("\033[34", str, i, 6);
		else if (!strncmp(str + *i, "{green}", 7))
			put_color("\033[32", str, i, 7);
		else if (!strncmp(str + *i, "{black}", 7))
			put_color("\033[30", str, i, 7);
		else if (!strncmp(str + *i, "{orange}", 8))
			put_color("\033[31", str, i, 8);
		else if (!strncmp(str + *i, "{yellow}", 8))
			put_color("\033[33", str, i, 8);
		else if (!strncmp(str + *i, "{pink}", 6))
			put_color("\033[35", str, i, 6);
		else if (!strncmp(str + *i, "{teal}", 6))
			put_color("\033[36", str, i, 6);
		else if (!strncmp(str + *i, "{normal}", 8))
			put_color("m\033[0m", str, i, 8);
	}
}
