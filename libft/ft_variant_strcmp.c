/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_variant_strcmp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kceder <kceder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:28:14 by kceder            #+#    #+#             */
/*   Updated: 2021/12/02 16:10:58 by kceder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_variant_strcmp(const char *str1, const char *str2)
{
	unsigned char	*s1;
	unsigned char	*s2;
	int				i;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}
