/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atilegen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 17:32:55 by atilegen          #+#    #+#             */
/*   Updated: 2018/03/24 12:37:57 by atilegen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *str, const char *s2)
{
	const char *s1;
	const char *t1;

	t1 = s2;
	if (*s2 == 0)
		return (char *)(str);
	while (*str)
	{
		if (*str != *s2)
		{
			str++;
			continue;
		}
		s1 = str;
		while (1)
		{
			if (!(*t1))
				return (char *)(s1 - ft_strlen(s2));
			if (*s1++ != *t1++)
				break ;
		}
		t1 = s2;
		str++;
	}
	return (0);
}
