/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 21:22:00 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/08/22 01:57:03 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main(void)
{
	t_gcext_list 	*gc;
	void			*lst;
	t_gc_list		*lst2;
	t_gc_list		*lst3;
	t_list			*root;

	int i = ft_gc_init();
	gc = ft_gc_start();
	if (!gc)
		return (0);
	ft_gc_new_root("pipe1");
	lst3 = ft_gcfct_register(ft_strdup("teste"), GC_DATA);
	lst2 = ft_gc_new_root("pipe2");
	printf("deu tudo certo");
	return (0);
}
