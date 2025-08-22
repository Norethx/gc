/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 09:57:31 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/08/22 01:50:45 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_gc_type
{
    GC_DATA,
    GC_ROOT,
    GC_SYSROOT,
    GC_META
} t_gc_type;

typedef struct s_gc_list
{
	void				*content;
	struct s_gc_list		*next;
	struct s_gc_list		*prev;
	t_gc_type			type;
	int					marked;
}						t_gc_list;

typedef struct s_list
{
	void				*content;
	struct s_list		*next;
	struct s_list		*prev;
}						t_list;

typedef struct s_gcext_list
{
	t_gc_list				*head;
	t_gc_list				*tail;
}						t_gcext_list;

typedef struct s_ext_list
{
	t_list				*head;
	t_list				*tail;
}						t_ext_list;

typedef struct s_root_list
{
	char				*categ;
	t_ext_list			*lst;
}						t_root_list;

typedef struct s_ext_root{
	t_root_list			root;
	t_root_list 		next;
	t_root_list 		prev;
}				t_ext_root;


t_gcext_list			*ft_gc_start(void);
void					ft_lstadd_back(t_ext_list **lst, t_list *new);
void					ft_gclstadd_back(t_gcext_list **lst, t_gc_list *new);
t_gc_list				*ft_gc_calloc(size_t nmemb, size_t size, t_gc_type type);
t_gc_list				*ft_gc_malloc(size_t size, t_gc_type type);
t_gc_list				*ft_gcfct_register(void *content, t_gc_type type);
t_ext_list				*ft_ext_newlst(void);
t_root_list				*ft_root_newlst(void);
char					*ft_strdup(const char *s);
int						ft_gc_rm(t_gc_list **lst);
int						ft_strcmp(const char *s1, const char *s2);
void					*ft_gc_new_root(char *categ);
void					*ft_calloc(size_t nmemb, size_t size);
int						ft_gc_init(void);
void					*ft_bzero(void *s, size_t n);
size_t					ft_strlen(const char *str);
void					ft_gclstdelone(t_gc_list **lst, void (*del)(void *));
void					ft_gc_mark(t_gc_list *lst);
void					ft_gc_sweep();
void					ft_gc_collect(void);



#endif
