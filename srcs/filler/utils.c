/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:07:35 by rodrodri          #+#    #+#             */
/*   Updated: 2022/03/09 20:55:08 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

char	**alloc_char_2darr(int rows, int cols)
{
	char	**arr;
	int		i;

	arr = (char **)malloc(sizeof(char *) * (rows + 1));
	if (!arr)
		return (0);
	ft_memset(arr, 0, sizeof(char *) * (rows + 1));
	i = 0;
	while (i < rows)
	{
		arr[i] = ft_strnew(cols);
		if (!arr[i])
		{
			free_char_2darr(arr);
			return (0);
		}
		i++;
		arr[i] = 0;
	}
	return (arr);
}

void	free_char_2darr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		ft_strdel(arr + i);
		i++;
	}
}
