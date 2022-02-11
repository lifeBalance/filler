/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:46:08 by rodrodri          #+#    #+#             */
/*   Updated: 2022/02/11 16:02:16 by rodrodri         ###   ########.fr       */
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

	arr = (int **)malloc(sizeof(int *) * (rows + 1));
	if (!arr)
		return (0);
	i = 0;
	while (i < rows)
	{
		arr[i] = (int *)malloc(sizeof(int) * cols);
		if (!arr[i])
		{
			free_int_2darr(arr);
			return (0);
		}
		i++;
		arr[i] = 0;
	}
	return (arr);
}

void	free_int_2darr(int **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
}
