/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_utility.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoutere <pnoutere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:39:37 by pnoutere          #+#    #+#             */
/*   Updated: 2022/05/16 18:06:01 by pnoutere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	adder_utils_help(char **str, char **add, t_utils utils)
{
	char	*temp;

	if (utils.sign > 0 && utils.plus)
		*str = character_adder(str, "+");
	if (utils.sign < 0)
	{
		temp = *str;
		*str = ft_strjoin("-", temp);
		free(temp);
	}
	if (utils.space && (*str[0] != '-' && *str[0] != '+'))
		*str = character_adder(str, " ");
	if (utils.dash)
	{
		temp = *str;
		*str = character_adder(add, temp);
		free(temp);
	}
	else
	{
		*str = character_adder(str, *add);
		free(*add);
	}
}

static char	*adder_utils(char *str, char *add, t_utils utils)
{
	if ((utils.sign < 0 || utils.plus
			|| utils.space || utils.dash) && !utils.zero)
		adder_utils_help(&str, &add, utils);
	else
	{
		str = character_adder(&str, add);
		free(add);
		str = check_helper(utils, utils.sign, str);
	}
	return (str);
}

static void	flag_adder_utils(t_utils utils, int *len)
{
	if (utils.plus && utils.sign > 0)
		*len -= 1;
	if (utils.sign < 0 && utils.space)
		*len -= 1;
	if (*len < 0)
		*len = 0;
}

char	*flag_adders(char *str, t_utils utils, int len)
{
	char	*temp;
	char	*add;

	if (utils.padding)
		utils.precision = utils.padding;
	len = utils.precision - ft_strlen(str);
	temp = str;
	if (str[0] == '-')
	{
		utils.sign = -1;
		str = str_maker(str);
	}
	else if (utils.space)
		len--;
	flag_adder_utils(utils, &len);
	add = ft_strnew(len);
	add = ft_memset(add, ' ', len);
	if (utils.dash)
		utils.zero = 0;
	if (utils.zero)
		add = ft_memset(add, '0', len);
	return (adder_utils(str, add, utils));
}
