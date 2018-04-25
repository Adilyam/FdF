/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atilegen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 12:36:16 by atilegen          #+#    #+#             */
/*   Updated: 2018/04/19 12:58:56 by atilegen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		aux(char s)
{
	if (s >= '0' && s <= '9')
		return (s - '0');
	if (s >= 'a' && s <= 'f')
		return (s - 'a' + 10);
	if (s >= 'A' && s <= 'F')
		return (s - 'A' + 10);
	return (0);
}

long int		ft_atoi_base(char *str, int base)
{
	int res;
	int i;
	int neg;

	i = 0;
	neg = 1;
	res = 0;
	if (!str)
		return (0);
	while (*str <= 32)
		str++;
	if (*str == '+')
		str++;
	if (*str == '-')
	{
		str++;
		neg = -1;
	}
	while ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'f')
			|| (str[i] >= 'A' && str[i] <= 'F'))
		res = res * base + (aux(str[i++]));
	return (res * neg);
}
