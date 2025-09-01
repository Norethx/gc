/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_rm_meta.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 19:01:03 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/09/01 19:26:36 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

static void	ft_gc_rm_meta_aux(t_ext_list **root, t_list *rm_root, int nb);

void	ft_gc_rm_meta(char *categ)
{
	t_gc_list		*aux;
	t_gcext_list	*all_allocs;
	t_list			*aux_tlist;

	all_allocs = ft_gc_start();
	aux_tlist = NULL;
	if (!all_allocs)
		return ;
	aux = all_allocs->head;
	while (aux && !(aux->type == GC_SYSROOT
			&& !ft_strcmp(((t_root_list *)aux->content)->categ, "gc_meta")))
		aux = aux->next;
	if (aux && aux->type == GC_SYSROOT
		&& !ft_strcmp(ft_to_root_list(aux)->categ, "gc_meta"))
		aux_tlist = ft_to_root_list(aux)->lst->head;
	while (aux_tlist)
	{
		if (!ft_strcmp(((t_gc_list *)aux_tlist->content)->content, categ))
		{
			ft_gc_rm_meta_aux(&(ft_to_root_list(aux)->lst), aux_tlist, 0);
			return ;
		}
		aux_tlist = aux_tlist->next;
	}
	return ;
}

static void	ft_gc_rm_meta_aux(t_ext_list **root, t_list *rm_root, int nb)
{
	t_gc_list	*aux;

	if (!*root || !rm_root)
		return ;
	if (nb < 1)
		ft_gc_rm_meta_aux(root, rm_root->next, nb + 1);
	if (root[0]->head == rm_root)
		root[0]->head = root[0]->head->next;
	if (root[0]->tail == rm_root)
		root[0]->tail = root[0]->tail->prev;
	if (rm_root->prev)
		rm_root->prev->next = rm_root->next;
	if (rm_root->next)
		rm_root->next->prev = rm_root->prev;
	aux = ((t_gc_list *)rm_root->content);
	ft_gc_rm(&aux);
	free(rm_root);
}
