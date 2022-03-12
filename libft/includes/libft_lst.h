/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_lst.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 11:09:18 by rodrodri          #+#    #+#             */
/*   Updated: 2022/02/15 00:00:56 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_LST_H
# define LIBFT_LST_H

/*
** Allowed headers.
*/
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

/*
** Type definitions.
*/
typedef struct s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}	t_list;

/*
** Singly Linked lists
*/
t_list	*ft_lstnew(void const *content, size_t content_size);
void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void	ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void	ft_lstadd(t_list **alst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void	ft_lstdelnode(t_list **l, t_list *n, void (*del)(void *c, size_t s));
void	ft_lstdelcont(void *content, size_t content_size);
size_t	lst_size(t_list *lst);
void	lst_prepend(t_list **lst, t_list *node);
void	lst_append(t_list **lst, t_list *node);

/*
** Circular Linked lists
*/

void	ft_clst_add(t_list **lst, t_list *node);
size_t	ft_clst_count(t_list *lst);
void	ft_clst_iter(t_list *clst, void (*f)(t_list *elem));
void	ft_clst_del(t_list **clst, void (*del)(void*, size_t));

#endif
