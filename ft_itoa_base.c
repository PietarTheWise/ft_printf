/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoutere <pnoutere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:11:45 by pnoutere          #+#    #+#             */
/*   Updated: 2022/05/18 18:02:46 by pnoutere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_reverse(char *str, int sign, int base)
{
	int		len;
	int		i;
	char	*temp;

	i = 0;
	len = ft_strlen(str);
	while (i < len / 2)
	{
		ft_swap(&str[i], &str[len - i - 1]);
		i++;
	}
	if (sign < 0 && base == 10)
	{
		temp = ft_strjoin("-", str);
		free(str);
		return (temp);
	}
	return (str);
}

static char	*assigner(int *sign, int *length, char **bases, long long *nb)
{
	char	*str;

	*sign = 1;
	*length = numlen(*nb);
	*bases = "0123456789ABCDEF";
	if (*nb < 0)
		*sign = -1;
	*nb *= *sign;
	str = (char *)malloc(sizeof(char) * (*length + 1));
	if (!str)
		exit (1);
	return (str);
}

static int	if_clauses(long long nb, int sign, char **str)
{
	if (nb == 0)
	{
		*str[0] = '0';
		return (1);
	}
	if (sign < 0)
		*str[0] = '-';
	return (0);
}

char	*itoa_base(int base, long long nb)
{
	int		sign;
	int		length;
	char	*bases;
	char	*str;
	int		i;

	if (check_nums(nb, base, &str))
		return (str);
	str = assigner(&sign, &length, &bases, &nb);
	ft_bzero(str, (size_t)length + 1);
	if (if_clauses(nb, sign, &str))
		return (str);
	i = 0;
	while (nb > 0)
	{
		if (i >= length)
			string_realloc(&str, &length);
		str[i] = bases[nb % base];
		i++;
		nb = nb / base;
	}
	return (ft_reverse(str, sign, base));
}

char	*u_itoa_base(int base, unsigned long long nb)
{
	int		length;
	char	*bases;
	char	*str;
	int		i;

	bases = "0123456789ABCDEF";
	length = numlen(nb);
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (!str)
		exit(1);
	ft_bzero(str, (size_t)length + 1);
	if (nb == 0)
	{
		str[0] = '0';
		return (str);
	}
	i = 0;
	while (nb > 0)
	{
		if (i >= length)
			string_realloc(&str, &length);
		str[i++] = bases[nb % base];
		nb = nb / base;
	}
	return (ft_reverse(str, 1, base));
}
