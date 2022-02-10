/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:46:08 by rodrodri          #+#    #+#             */
/*   Updated: 2022/02/10 22:46:38 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "heatmap.h"

int	max_int(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int	**alloc_int_2darr(int rows, int cols)
{
	int	**arr;
	int	i;

	arr = (int **)malloc(sizeof(int *) * rows);
	if (!arr)
		return (0);
	i = 0;
	while (i < rows)
	{
		arr[i] = (int *)malloc(sizeof(int) * cols);
		if (!arr[i])
		{
			free_int_2darr(arr, rows);
			return (0);
		}
		i++;
	}
	return (arr);
}

void	free_int_2darr(int **arr, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(arr + i);
		i++;
	}
	ft_memdel((void **)arr);
}
