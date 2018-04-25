/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atilegen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 22:02:06 by atilegen          #+#    #+#             */
/*   Updated: 2018/03/25 18:19:19 by atilegen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*pd;
	const unsigned char *ps;

	pd = dest;
	ps = src;
	if (ps < pd)
	{
		pd += n;
		ps += n;
		while (n--)
			*--pd = *--ps;
	}
	else
		while (n--)
			*pd++ = *ps++;
	return (dest);
}
