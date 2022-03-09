/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:03:50 by rodrodri          #+#    #+#             */
/*   Updated: 2022/03/09 20:28:07 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"
#include "logging.h"

static int	check_collisions(t_filler *f);
static void	smarty_pants(t_filler *f);

int	place_piece(t_filler *f)
{
	make_heatmap(f);
	flog_heatmap(f->file, f->heatmap, f->b_rows, f->b_cols);// <=======Don't forget to delete this!!!
	f->min = 0;
	f->y = 0;
	while (f->y + f->p_rows <= f->b_rows)
	{
		f->x = 0;
		while (f->x + f->p_cols <= f->b_cols)
		{
			if (check_collisions(f) == 0)
				smarty_pants(f);
			f->x++;
		}
		f->y++;
	}
	if (f->min)
		return (0);
	return (-1);
}

static int	check_collisions(t_filler *f)
{
	int		i;
	int		j;
	int		single_collision;
	char	cell;
	
	single_collision = 0;
	i = 0;
	while (i < f->p_rows)
	{
		j = 0;
		while (j < f->p_cols && single_collision <= 1)
		{
			cell = ft_toupper(f->board[f->y + i][f->x + j]);
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

static void	smarty_pants(t_filler *f)
{
	if (f->our_playa == PLAYA1)
	{
		if (f->heatmap[f->y][f->x] <= f->min || f->min == 0)
		{
			f->min = f->heatmap[f->y][f->x];
			f->min_y = f->y;
			f->min_x = f->x;
		}
	}
	else
	{
		if (f->heatmap[f->y][f->x] < f->min || f->min == 0)
		{
			f->min = f->heatmap[f->y][f->x];
			f->min_y = f->y;
			f->min_x = f->x;
		}
	}
}
