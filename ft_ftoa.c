/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoutere <pnoutere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:03:11 by pnoutere          #+#    #+#             */
/*   Updated: 2022/05/18 17:15:01 by pnoutere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	concat_num_strings_utils(char **pre_dot_str,
	char **after_dot, char **str, t_utils utils)
{
	char	*tmp;

	if (utils.precision == 1)
	{
		if (*after_dot[0] >= '6' || (*after_dot[0] == '5'
				&& ft_isdigit(utils._char) && utils._char > '0'))
			rounding(*pre_dot_str);
		else if (*after_dot[0] == '5')
		{
			if (utils._ulong_long % 2 == 1)
				rounding(*pre_dot_str);
		}
		*str = ft_strdup(*pre_dot_str);
		if (utils.hashtag)
		{
			tmp = *str;
			*str = ft_strjoin(tmp, ".");
			free (tmp);
		}
	}
	else
	{
		*after_dot = character_adder(after_dot, ".");
		*str = ft_strjoin(*pre_dot_str, *after_dot);
	}
}

static void	concat_num_strings(unsigned long long pre_dot,
	char **after_dot, char **str, t_utils utils)
{
	char	*pre_dot_str;
	char	*tmp;

	pre_dot_str = u_itoa_base(10, pre_dot);
	if (utils.sign < 0 && (!utils.zero || ft_strcmp(pre_dot_str, "0")))
	{
		tmp = pre_dot_str;
		pre_dot_str = ft_strjoin("-", pre_dot_str);
		free (tmp);
	}
	if (utils.precision - 1 && !utils.dot)
	{
		*after_dot = character_adder(&(*after_dot), ".");
		*str = ft_strjoin(pre_dot_str, *after_dot);
	}
	else
	{
		utils._ulong_long = pre_dot;
		concat_num_strings_utils(&pre_dot_str, after_dot, str, utils);
	}
	free (pre_dot_str);
	free (*after_dot);
}

int	ftoa_loop(long double f, int precision, char *after_dot)
{
	int	i;
	int	single;

	i = 0;
	while (precision--)
	{
		f *= 10;
		single = f;
		f -= single;
		after_dot[i] = '0' + single;
		i++;
	}
	return (i);
}

static void	stringify_and_check(char *after_dot, int i,
	unsigned long long *pre_dot)
{
	stringify_float(after_dot, i - 1);
	if (after_dot[0] > '9')
	{
		after_dot[0] = '0';
		*pre_dot += 1;
	}
	if ((i - 1) > 0)
		after_dot[i - 1] = '\0';
}

char	*ft_ftoa(long double f, t_utils utils, t_ldouble_cast un)
{
	unsigned long long			pre_dot;
	char						*str;
	char						*after_dot;
	int							i;

	utils.precision++;
	after_dot = (char *)malloc(sizeof(char) * (utils.precision + 1));
	if (!after_dot)
		exit (1);
	utils.sign = 1;
	if (f < 0 || (un.s_parts.sign))
	{
		f *= -1;
		utils.sign = -1;
	}
	pre_dot = f;
	f = pre_dot - f;
	if (f < 0)
		f *= -1;
	i = 0;
	find_second_nb(f, &utils);
	i = ftoa_loop(f, utils.precision, after_dot);
	stringify_and_check(after_dot, i, &pre_dot);
	concat_num_strings(pre_dot, &after_dot, &str, utils);
	return (str);
}
