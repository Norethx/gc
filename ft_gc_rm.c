/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_rm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 21:22:56 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/08/31 19:49:08 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_gc_rm(t_gc_list **lst)
{
	t_gcext_list	*all_allocs;

	all_allocs = ft_gc_start();
	if (!all_allocs || !lst[0])
		return (1);
	if (all_allocs->head && lst[0] == all_allocs->head)
	{
		all_allocs->head = all_allocs->head->next;
		if (all_allocs->head)
			all_allocs->head->prev = NULL;
	}
	else if (all_allocs->tail && lst[0] == all_allocs->tail)
	{
		all_allocs->tail = all_allocs->tail->prev;
		if (all_allocs->tail)
			all_allocs->tail->next = NULL;
	}
	else
		lst[0]->prev->next = lst[0]->next;
	ft_gclstdelone(lst, &free);
	if (!all_allocs->head)
		all_allocs->tail = NULL;
	return (0);
}
