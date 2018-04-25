/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atilegen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 21:48:52 by atilegen          #+#    #+#             */
/*   Updated: 2018/03/25 21:48:55 by atilegen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *elem;

	elem = *begin_list;
	if (*begin_list)
	{
		while (elem->next)
			elem = elem->next;
		elem->next = ft_create_elem(data);
	}
}
