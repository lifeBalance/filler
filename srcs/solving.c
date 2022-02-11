/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:03:50 by rodrodri          #+#    #+#             */
/*   Updated: 2022/02/11 23:01:24 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"
#include "heatmap.h"

static int	measure_piece(t_filler *f, int *height, int *width);

int	make_filler_heatmap(t_filler *f, t_heatmap *hm)
{
	int	i;
	int	j;

	i = 0;
	while (i < f->b_rows)
	{
		j = 0;
		while (j < f->b_cols)
		{
			if (f->board[i][j] == f->other_playa)
				hm->map[i][j] = -1;
			j++;
		}
		i++;
	}
	make_heatmap(hm);
	return (0);
}

int	place_piece(t_filler *f, t_heatmap *hm)
{
	int	height;
	int	width;
	// int	min;
	(void)hm;
	measure_piece(f, &height, &width);
	ft_printf("Piece has width %d and height %d\n", width, height);
	// Traverse the board checking for:
	// 1. Must be a single collision with other piece
	// 2. Must be zero collisions with the borders
	// The heatmap must be traversed simultaneously to find the most
	// favourable position (smaller value) that we'll keep in 'min'(for now).
	// When the loop ends, we check if there's a position set,
	// and print these coordinates, '0 0\n' otherwise (and exit).
	return (0);
}

int	measure_piece(t_filler *f, int *height, int *width)
{
	int	i;
	int	j;

	*height = f->p_rows;
	i = f->p_rows - 1;
	while (i > 0)
	{
		j = 0;
		while (j < f->p_cols)
		{
			if (f->piece[i][j] != '.')
				break ;
			j++;
		}
		if (j == f->p_cols)
			(*height)--;
		else
			break ;
		i--;
	}
	*width = f->p_cols;
	j = f->p_cols - 1;
	while (j > 0)
	{
		i = 0;
		while (i < f->p_rows)
		{
			if (f->piece[i][j] != '.')
				break ;
			i++;
		}
		if (i == f->p_rows)
			(*width)--;
		else
			break ;
		j--;
	}
	return (0);
}

void	print_filler_heatmap(t_heatmap *hm)
{
	int	i;
	int	j;

	i = 0;
	while (i < hm->rows)
	{
		j = 0;
		while (j < hm->cols)
		{
			printf("%4d", hm->map[i][j]);
			j++;
		}
		printf("\n\n");
		i++;
	}
}
