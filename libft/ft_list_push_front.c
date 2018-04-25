/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atilegen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 21:49:07 by atilegen          #+#    #+#             */
/*   Updated: 2018/03/25 21:49:11 by atilegen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *n_elem;

	n_elem = ft_create_elem(data);
	n_elem->next = *begin_list;
	*begin_list = n_elem;
}
