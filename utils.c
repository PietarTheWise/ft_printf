/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoutere <pnoutere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:21:05 by pnoutere          #+#    #+#             */
/*   Updated: 2022/05/18 18:03:43 by pnoutere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	calc_zeros(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (ft_isdigit(str[i]))
	{
		if (str[i] != '0')
			break ;
		i++;
	}
	return (i);
}

void	string_realloc(char **str, int *length)
{
	char	*temp;

	*length *= 2;
	temp = (char *)malloc(sizeof(char) * (*length + 1));
	if (!temp)
		exit(1);
	ft_bzero(temp, *length + 1);
	ft_strcpy(temp, *str);
	free(*str);
	*str = temp;
}

void	putnstr(char *str, int limit)
{
	int	i;

	i = 0;
	while (i < limit)
	{
		ft_putchar(str[i]);
		i++;
	}
}

char	*character_adder(char **str, char *add)
{
	char	*res;

	res = ft_strjoin(add, *str);
	free (*str);
	return (res);
}

int	read_args(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '%')
			count++;
		i++;
	}
	return (count);
}
