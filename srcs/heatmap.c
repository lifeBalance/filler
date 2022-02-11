/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:46:17 by rodrodri          #+#    #+#             */
/*   Updated: 2022/02/11 16:07:15 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "heatmap.h"

static void	surround(t_heatmap *hm);
static void	surround_east(t_heatmap *hm, int n, int i);
static void	surround_west(t_heatmap *hm, int n, int i);

int	hm_init(t_heatmap *hm, int rows, int cols, int val)
{
	int	i;
	int	j;

	hm->map = alloc_int_2darr(rows, cols);
	if (!hm->map)
		return (-1);
	hm->rows = rows;
	hm->cols = cols;
	hm->r = 0;
	hm->c = 0;
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
			hm->map[i][j++] = val;
		i++;
	}
	return (0);
}

int	make_heatmap(t_heatmap *hm)
{
	hm->r = 0;
	while (hm->r < hm->rows)
	{
		hm->c = 0;
		while (hm->c < hm->cols)
		{
			if (hm->map[hm->r][hm->c] < 0)
				surround(hm);
			hm->c++;
		}
		hm->r++;
	}
	return (0);
}

static void	surround(t_heatmap *hm)
{
	int	i;
	int	n;

	n = 1;
	while (n <= max_int(hm->rows, hm->cols))
	{
		i = 0;
		while (i <= n)
		{
			surround_west(hm, n, i);
			surround_east(hm, n, i);
			i++;
		}
		n++;
	}
}

static void	surround_west(t_heatmap *hm, int n, int i)
{
	int	**arr;
	int	r;
	int	c;

	arr = hm->map;
	r = hm->r;
	c = hm->c;
	if (r - i >= 0 && c - n >= 0)
		if (arr[r - i][c - n] == 0 || arr[r - i][c - n] > n)
			arr[r - i][c - n] = n;
	if (r - n >= 0 && c - i >= 0)
		if (arr[r - n][c - i] == 0 || arr[r - n][c - i] > n)
			arr[r - n][c - i] = n;
	if (r + i < hm->rows && c - n >= 0)
		if (arr[r + i][c - n] == 0 || arr[r + i][c - n] > n)
			arr[r + i][c - n] = n;
	if (r + n < hm->rows && c - i >= 0)
		if (arr[r + n][c - i] == 0 || arr[r + n][c - i] > n)
			arr[r + n][c - i] = n;
}

static void	surround_east(t_heatmap *hm, int n, int i)
{
	int	**arr;
	int	r;
	int	c;

	arr = hm->map;
	r = hm->r;
	c = hm->c;
	if (r - n >= 0 && c + i < hm->cols)
		if (arr[r - n][c + i] == 0 || arr[r - n][c + i] > n)
			arr[r - n][c + i] = n;
	if (r - i >= 0 && c + n < hm->cols)
		if (arr[r - i][c + n] == 0 || arr[r - i][c + n] > n)
			arr[r - i][c + n] = n;
	if (r + i < hm->rows && c + n < hm->cols)
		if (arr[r + i][c + n] == 0 || arr[r + i][c + n] > n)
			arr[r + i][c + n] = n;
	if (r + n < hm->rows && c + i < hm->cols)
		if (arr[r + n][c + i] == 0 || arr[r + n][c + i] > n)
			arr[r + n][c + i] = n;
}
