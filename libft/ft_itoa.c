/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atilegen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:09:13 by atilegen          #+#    #+#             */
/*   Updated: 2018/03/25 17:56:58 by atilegen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

static int	len(int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*res;
	int		ali;
	int		neg;

	neg = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	n = ft_abs(n);
	ali = len(n);
	if (neg < 0)
		res = (char *)malloc(ali++ + 2);
	else
		res = (char *)malloc(ali + 1);
	if (!res)
		return (NULL);
	res[ali] = '\0';
	while (ali--)
	{
		res[ali] = n % 10 + '0';
		n = n / 10;
	}
	if (neg < 0)
		res[0] = '-';
	return (res);
}
