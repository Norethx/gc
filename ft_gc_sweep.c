/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_sweep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:01:43 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/08/22 19:44:36 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_clean_allocs(t_gc_list **lst);

void	ft_gc_sweep(void)
{
	t_gcext_list	*gc;
	t_gc_list		*aux;

	gc = ft_gc_start();
	if (!gc)
		return ;
	aux = gc->head;
	while (aux)
	{
		if (aux->type == GC_DATA && !aux->marked)
		{
			aux->prev->next = aux->next;
			if (aux == gc->tail)
				gc->tail = aux->prev;
			ft_clean_allocs(&aux);
		}
		else
		{
			aux->marked = 0;
			aux = aux->next;
		}
	}
	if (!gc->head)
		gc->tail = NULL;
	return ;
}

static void	ft_clean_allocs(t_gc_list **lst)
{
	t_gc_list	*aux;

	aux = lst[0];
	lst[0] = aux->next;
	if (aux->content)
		ft_gclstdelone(&aux, free);
	free(aux);
}
