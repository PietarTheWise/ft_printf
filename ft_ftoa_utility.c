/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa_utility.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoutere <pnoutere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:46:57 by pnoutere          #+#    #+#             */
/*   Updated: 2022/05/18 17:16:59 by pnoutere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	rounding(char *float_nums)
{
	int	i;

	i = (int)ft_strlen(float_nums);
	i--;
	while (i >= 0)
	{
		if ((float_nums[i] + 1) <= '9')
		{
			float_nums[i] += 1;
			break ;
		}
		else
			float_nums[i] = '0';
		i--;
	}
}

void	find_second_nb(long double f, t_utils *utils)
{
	char	str[4];

	str[3] = '\0';
	ftoa_loop(f, 3, str);
	if (str[1] == '0' && str[2] >= '5')
		utils->_char = '1';
	else
		utils->_char = str[1];
}
