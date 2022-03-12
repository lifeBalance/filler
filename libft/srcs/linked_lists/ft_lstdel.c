/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 14:41:03 by rodrodri          #+#    #+#             */
/*   Updated: 2022/02/14 23:56:32 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_lst.h"

/*
**	Deletes a linked-list. It takes two arguments:
**	- The address of the list.
**	- A pointer to a function to free each node's content.
**	At the end, the original heads points to NULL (no dangling pointer).
*/
void	ft_lstdel(t_list **alst, void (*del)(void* cont, size_t cont_size))
{
	t_list	*temp_head;

	if (!alst || !del)
		return ;
	if (*alst)
	{
		temp_head = *alst;
		while (temp_head)
		{
			*alst = temp_head->next;
			ft_lstdelone(&temp_head, del);
			temp_head = *alst;
		}
	}
}
