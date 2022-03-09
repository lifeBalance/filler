/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:46:17 by rodrodri          #+#    #+#             */
/*   Updated: 2022/03/09 16:03:08 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

static void	surround(t_filler *f);
static void	surround_east(t_filler *f, int n, int i);
static void	surround_west(t_filler *f, int n, int i);
static int	complete_heatmap(t_filler *f);

int	make_heatmap(t_filler *f)
{
	int	i;
	int	j;

	i = 0;
	while (i < f->b_rows)
	{
		j = 0;
		while (j < f->b_cols)
		{
			if (ft_toupper(f->board[i][j]) == f->other_playa)
				f->heatmap[i][j] = -1;
			else
				f->heatmap[i][j] = 0;
			j++;
		}
		i++;
	}
	complete_heatmap(f);
	return (0);
}

static int	complete_heatmap(t_filler *f)
{
	int	i;
	int	j;

	i = 0;
	while (i < f->b_rows)
	{
		j = 0;
		while (j < f->b_cols)
		{
			if (f->heatmap[i][j] < 0)
			{
				f->y = i;
				f->x = j;
				surround(f);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static void	surround(t_filler *f)
{
	int	i;
	int	n;

	n = 1;
	while (n <= max_int(f->b_rows, f->b_cols))
	{
		i = 0;
		while (i <= n)
		{
			surround_west(f, n, i);
			surround_east(f, n, i);
			i++;
		}
		n++;
	}
}

static void	surround_west(t_filler *f, int n, int i)
{
	int	**arr;
	int	r;
	int	c;

	arr = f->heatmap;
	r = f->y;
	c = f->x;
	if (r - i >= 0 && c - n >= 0)
		if (arr[r - i][c - n] == 0 || arr[r - i][c - n] > n)
			arr[r - i][c - n] = n;
	if (r - n >= 0 && c - i >= 0)
		if (arr[r - n][c - i] == 0 || arr[r - n][c - i] > n)
			arr[r - n][c - i] = n;
	if (r + i < f->b_rows && c - n >= 0)
		if (arr[r + i][c - n] == 0 || arr[r + i][c - n] > n)
			arr[r + i][c - n] = n;
	if (r + n < f->b_rows && c - i >= 0)
		if (arr[r + n][c - i] == 0 || arr[r + n][c - i] > n)
			arr[r + n][c - i] = n;
}

static void	surround_east(t_filler *f, int n, int i)
{
	int	**arr;
	int	r;
	int	c;

	arr = f->heatmap;
	r = f->y;
	c = f->x;
	if (r - n >= 0 && c + i < f->b_cols)
		if (arr[r - n][c + i] == 0 || arr[r - n][c + i] > n)
			arr[r - n][c + i] = n;
	if (r - i >= 0 && c + n < f->b_cols)
		if (arr[r - i][c + n] == 0 || arr[r - i][c + n] > n)
			arr[r - i][c + n] = n;
	if (r + i < f->b_rows && c + n < f->b_cols)
		if (arr[r + i][c + n] == 0 || arr[r + i][c + n] > n)
			arr[r + i][c + n] = n;
	if (r + n < f->b_rows && c + i < f->b_cols)
		if (arr[r + n][c + i] == 0 || arr[r + n][c + i] > n)
			arr[r + n][c + i] = n;
}
