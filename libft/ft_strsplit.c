/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atilegen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 12:34:58 by atilegen          #+#    #+#             */
/*   Updated: 2018/03/25 17:40:25 by atilegen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		splits(const char *str, char c)
{
	int count;
	int i;

	i = 1;
	if (*str == '\0')
		return (0);
	count = 0;
	if (str[0] != c)
		count++;
	while (str[i])
	{
		if (str[i] != c && str[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

static int		len(const char *str, int j, int c)
{
	int k;

	k = 0;
	while (str[j] != c && str[j])
	{
		j++;
		k++;
	}
	return (k);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		w;
	int		j;
	int		i;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	arr = (char**)malloc(sizeof(char*) * (splits(s, c) + 1));
	if (!arr)
		return (0);
	while (i < splits(s, c))
	{
		while (s[j] == c && s[j])
			j++;
		w = 0;
		arr[i] = malloc(sizeof(char) * (len(s, j, c) + 1));
		while (s[j] != c && s[j])
			arr[i][w++] = s[j++];
		arr[i++][w] = '\0';
	}
	arr[i] = 0;
	return (arr);
}
