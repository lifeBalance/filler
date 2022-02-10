/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:03:50 by rodrodri          #+#    #+#             */
/*   Updated: 2022/02/10 23:19:02 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"
#include "heatmap.h"

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
