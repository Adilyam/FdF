/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atilegen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 23:25:43 by atilegen          #+#    #+#             */
/*   Updated: 2018/03/25 13:58:28 by atilegen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dup;
	char	*dup_offset;

	i = 0;
	dup = (char *)malloc((ft_strlen(s1) + 1));
	if (!dup)
		return (NULL);
	dup_offset = dup;
	while (s1[i])
	{
		dup_offset[i] = s1[i];
		i++;
	}
	dup_offset[i] = '\0';
	return (dup);
}
