/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atilegen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 12:28:56 by atilegen          #+#    #+#             */
/*   Updated: 2018/03/24 12:33:32 by atilegen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	char	*ret;

	ret = dst;
	i = 0;
	while (src[i] && len)
	{
		if (!len--)
			return (dst);
		dst[i] = src[i];
		i++;
	}
	while (len--)
	{
		dst[i] = 0;
		i++;
	}
	return (ret);
}
