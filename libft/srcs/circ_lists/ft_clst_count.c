/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clst_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 14:41:03 by rodrodri          #+#    #+#             */
/*   Updated: 2022/02/02 17:26:16 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_lst.h"

size_t	ft_clst_count(t_list *clst)
{
	t_list	*tmp;
	size_t	count;

	if (!clst)
		return (0);
	count = 1;
	tmp = clst->next;
	while (tmp && clst != tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}
