/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atilegen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:15:46 by atilegen          #+#    #+#             */
/*   Updated: 2018/04/23 17:13:03 by atilegen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char *str)
{
	long long int	res;
	int				i;
	long long int	n;

	res = 1;
	i = 0;
	n = 0;
	while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\r' ||
			str[i] == '\f' || str[i] == '\v' || str[i] == '\n') && str[i])
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			res = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57 && n >= 0)
		n = n * 10 + (long long int)(str[i++] - '0');
	if (n < 0)
	{
		if (res == -1)
			return (0);
		return (-1);
	}
	return ((int)n * (int)res);
}
