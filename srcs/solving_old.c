/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:03:50 by rodrodri          #+#    #+#             */
/*   Updated: 2022/02/14 13:02:47 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"
#include "heatmap.h"

static void init_zero(int *arr, int size);
static void	init_pos(int min[3]);
static int	find_position(t_filler *f, t_heatmap *hm, int min[3]);
static int	check_collisions(t_filler *f, int row, int col);

int	make_filler_heatmap(t_filler *f, t_heatmap *hm)
{
	int	i;
	int	j;

	i = 0;
	while (i < f->b_rows)
	{
		init_zero(hm->map[i], f->b_cols);
		j = 0;
		while (j < f->b_cols)
		{
			if (ft_toupper(f->board[i][j]) == f->other_playa)
				hm->map[i][j] = -1;
			j++;
		}
		i++;
	}
	make_heatmap(hm);
	return (0);
}

static void	init_zero(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i] = 0;
		i++;
	}
}
/*
**	It declares an array (pos) of 4 integers:
**	- index 0 for the heatmap value at that position (row, col)
**	- index 1 for the row itself.
**	- index 2 for the column.
**	It invokes a function to do the job of finding the position and returns:
**	- zero if there's no suitable position for the piece.
**	- one, otherwise.
**	It also prints the position to standard output.
*/
int	place_piece(t_filler *f, t_heatmap *hm)
{
	int	pos[3];

	init_pos(pos);
	if (find_position(f, hm, pos) < 0)
	{
		ft_printf("0 0\n");
		return (-1);
	}
	else
	{
		ft_printf("%d %d\n", pos[1], pos[2]);
		return (0);
	}
}

/*	Traverse the board checking for a valid position for the piece. On each
**	iteration invokes the 'check_collisions' function, which returns 1 if the
**	piece can be placed, 0 otherwise.
**	The heatmap must be traversed simultaneously to find the most
**	favourable position (smaller value greater or equal to 1)
**	that we'll keep in 'pos[0]'(for now).
**	Returns 1 if the position was found, -1 if it didn't.
*/
static int	find_position(t_filler *f, t_heatmap *hm, int pos[3])
{
	int	i;
	int	j;

	i = 0;
	while (i < f->b_rows)
	{
		j = 0;
		while (j < f->b_cols)
		{
			if (check_collisions(f, i, j) == 0 && \
				(hm->map[i][j] <= pos[0] || pos[0] == 0))
			{
				pos[0] = hm->map[i][j];
				pos[1] = i;
				pos[2] = j;
			}
			j++;
		}
		i++;
	}
	if (pos[0] > 0)
		return (0);
	else
		return (-1);
}

/*
**	Traverses simultaneously both the piece and the board checking for
**	collisions:
**	 1. There must be a single collision with other piece.
**	 2. There must be no collisions with the borders of the board.
**	Returns 1 if the piece can be placed, 0 otherwise.
*/
static int	check_collisions(t_filler *f, int row, int col)
{
	int	i;
	int	j;
	int	single_collision;
	char	cell;
	
	// if (row + f->p_height > f->b_rows || col + f->p_width > f->b_cols)
	if (row + f->p_rows > f->b_rows || col + f->p_cols > f->b_cols)
		return (-1);
	single_collision = 0;
	i = 0;
	while (i < f->p_rows)
	{
		j = 0;
		while (j < f->p_cols && single_collision <= 1)
		{
			cell = ft_toupper(f->board[i + row][j + col]);
			if (f->piece[i][j] == '*' && cell == f->our_playa)
				single_collision++;
			else if (f->piece[i][j] == '*' && cell == f->other_playa)
				return (-1);
			j++;
		}
		i++;
	}
	if (single_collision == 1)
		return (0);
	return (-1);
}

static void	init_pos(int pos[3])
{
	pos[0] = 0;
	pos[1] = 0;
	pos[2] = 0;
}
