/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:03:50 by rodrodri          #+#    #+#             */
/*   Updated: 2022/03/05 12:25:55 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

static int	check_collisions(t_filler *f);

int	place_piece(t_filler *f)
{
	write(f->file, "---solving---\n", ft_strlen("---solving---\n"));// <=======Don't forget to delete this!!!
	f->y = 0;
	while (f->y + f->p_rows <= f->b_rows)
	{
		f->x = 0;
		while (f->x + f->p_cols <= f->b_cols)
		{
			if (check_collisions(f) == 0)
				return (0);
			f->x++;
		}
		f->y++;
	}
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
