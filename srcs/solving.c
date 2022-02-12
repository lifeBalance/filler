/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:03:50 by rodrodri          #+#    #+#             */
/*   Updated: 2022/02/12 17:58:45 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"
#include "heatmap.h"

static void	init_min(int min[4]);

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
	// int	height;
	// int	width;
	int	min[4]; // idx 0 for the 'set' value, 1 for the value itself, 2 for the row, 3 for the column.

	init_min(min);
	// measure_piece(f, &height, &width);
	// ft_printf("Piece has width %d and height %d\n", width, height);
	(void)hm;
	(void)f;
	return (1);
	// if (find_position(f, hm))
	// {
	// 	// ft_printf("%d %d\n", f->);
	// 	return (1);
	// }
	// else
	// 	return (-1);
	// When the loop ends, we check if there's a position set,
	// and print the coordinates in min[1] and min[2]; '0 0\n' otherwise (in
	// that case we'll exit).
	return (0);
}

/*	Traverse the board checking for a valid position for the piece. On each
**	iteration invokes the 'check_collisions' function, which returns 1 if the
**	piece can be placed, 0 otherwise.
**	The heatmap must be traversed simultaneously to find the most
**	favourable position (smaller value greater or equal to 1)
**	that we'll keep in 'min[0]'(for now).
**	Returns 1 if the position was found, -1 if it didn't.
*/
// static int	find_position(t_filler *f, t_heatmap *hm, int min[4])
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < f->p_rows)
// 	{
// 		j = 0;
// 		while (i < f->p_cols)
// 		{
// 			if (check_collisions(f, i, j) && hm->map[i][j] <= min[1])
// 			{
// 				min[0] = 1;
// 				min[1] = hm->map[i][j];
// 				min[2] = i;
// 				min[3] = j;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	if (min[0])
// 		return (1);
// 	else
// 		return (-1);
// }

/*
**	Traverses simultaneously both the piece and the board checking for
**	collisions:
**	 1. There must be a single collision with other piece.
**	 2. There must be no collisions with the borders of the board.
**	Returns 1 if the piece can be placed, 0 otherwise.
*/
// static int	check_collisions(t_filler *f, int row, int col)
// {
// 	int	i;
// 	int	j;
// 	int	single_collision;
	
// 	single_collision = 0;
// 	i = 0;
// 	while (i < f->p_rows)
// 	{
// 		j = 0;
// 		while (i < f->p_cols)
// 		{
// 			if (i + p_height > )
// 			j++;
// 		}
// 		i++;
// 	}
// }

static void	init_min(int min[4])
{
	min[0] = 0;
	min[1] = 0;
	min[2] = 0;
	min[3] = 0;
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
