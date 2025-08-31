/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_del_root.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 10:03:37 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/08/31 20:30:44 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_gc_del_root(char *categ)
{
	t_list		*aux;
	t_root_list *aux_root[2];
	
	aux = ft_gc_clean_root(categ);
	aux_root[0] = aux->content;
	if (!aux_root[0])
		return ;
	aux_root[1] = ft_fix_root();
	if (!aux_root[1] || !aux_root[0])
		return ;
	if (aux_root[1]->lst->head == aux)
		aux_root[1]->lst->head = aux_root[1]->lst->head->next;
	if (aux_root[1]->lst->tail == aux)
		aux_root[1]->lst->tail = aux_root[1]->lst->tail->prev;
	if (aux->prev)
		aux->prev->next = aux->next;
	if (aux->next)
		aux->next->prev = aux->prev;
	ft_gc_rm_meta(categ);
	free(aux->content);
	free(aux);
}

static t_root_list *ft_fix_root()
{
	t_gc_list		*aux;
	t_gcext_list	*all_allocs;

	all_allocs = ft_gc_start();
	if (!all_allocs)
		return (NULL);
	aux = all_allocs->head;
	while (aux && !(aux->type == GC_SYSROOT
			&& !ft_strcmp(((t_root_list *)aux->content)->categ, "gc_roots")))
		aux = aux->next;
	if (aux->type == GC_SYSROOT 
			&& !ft_strcmp(ft_to_root_list(aux)->categ , "gc_roots"))
		return (((t_root_list *)aux->content)->lst);
	else
		return (NULL);
}


