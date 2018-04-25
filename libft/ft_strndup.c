/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atilegen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 21:16:26 by atilegen          #+#    #+#             */
/*   Updated: 2018/04/04 21:22:46 by atilegen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t len)
{
	int		i;
	char	*dup;
	char	*dup_offset;

	i = 0;
	dup = (char *)malloc(len + 1);
	if (!dup)
		return (NULL);
	dup_offset = dup;
	while (s1[i] && len--)
	{
		dup_offset[i] = s1[i];
		i++;
	}
	dup_offset[i] = '\0';
	return (dup);
}
