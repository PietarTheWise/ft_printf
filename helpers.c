/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoutere <pnoutere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:28:23 by pnoutere          #+#    #+#             */
/*   Updated: 2022/05/12 17:47:04 by pnoutere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check_helper(t_utils utils, int sign, char *str)
{
	if (utils.zero && sign < 0 && ft_strlen(str) <= 1)
		str = character_adder(&str, "0");
	else if (utils.zero && utils.plus && ft_strlen(str) <= 1)
		str = character_adder(&str, "0");
	if (utils.sign > 0 && utils.plus)
		str = character_adder(&str, "+");
	if (utils.sign < 0)
		str = character_adder(&str, "-");
	if (utils.space && utils.sign > 0 && !utils.plus)
		str = character_adder(&str, " ");
	return (str);
}

int	numlen(long long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_to_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

void	ft_swap(char *a, char *b)
{
	char	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

long long	ft_absolute(long long int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
