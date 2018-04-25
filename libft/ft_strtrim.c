/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atilegen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 12:29:19 by atilegen          #+#    #+#             */
/*   Updated: 2018/03/26 00:04:26 by atilegen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ali(char const *s, int *start, int *last)
{
	while (s[*start])
	{
		if (s[*start] != '\n' && s[*start] != ' ' && s[*start] != '\t')
			break ;
		*start = *start + 1;
	}
	while (s[*last] && *last + 1 >= *start)
	{
		if (s[*last] != '\n' && s[*last] != ' ' && s[*last] != '\t')
			break ;
		*last = *last - 1;
	}
}

char			*ft_strtrim(char const *s)
{
	int		start;
	int		last;
	char	*res;
	int		i;

	if (!s)
		return (0);
	last = ft_strlen(s) - 1;
	start = 0;
	ali(s, &start, &last);
	res = ft_strnew(last - start + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (start <= last)
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}
