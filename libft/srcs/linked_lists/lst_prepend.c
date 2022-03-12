/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_prepend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 14:41:03 by rodrodri          #+#    #+#             */
/*   Updated: 2022/02/14 23:13:49 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_lst.h"

/*
**	It adds the node received as second argument, to
**	the beginning of the list, received as first argument.
*/
void	lst_prepend(t_list **lst, t_list *node)
{
	if (!lst || !node)
		return ;
	if (!(*lst))
		*lst = node;
	else
	{
		node->next = *lst;
		*lst = node;
	}
}
