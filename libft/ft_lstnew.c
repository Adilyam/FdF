/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atilegen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 20:07:58 by atilegen          #+#    #+#             */
/*   Updated: 2018/03/25 22:48:25 by atilegen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *elem;

	elem = (t_list *)malloc(sizeof(elem) * content_size);
	if (!elem)
		return (0);
	if (!content)
	{
		elem->content = NULL;
		elem->content_size = 0;
	}
	else
	{
		elem->content = malloc(sizeof(content));
		if (!elem->content)
			return (NULL);
		ft_memmove(elem->content, content, content_size);
		elem->content_size = content_size;
		elem->next = NULL;
		return (elem);
	}
	elem->next = NULL;
	return (elem);
}
