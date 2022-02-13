/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:22:48 by rodrodri          #+#    #+#             */
/*   Updated: 2022/02/13 23:55:18 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"
#include "heatmap.h"

static int	init_filler(t_filler *f, t_heatmap *hm);

int	main(void)
{
	t_filler	f;
	t_heatmap	hm;
	int			ret;
	int			i;

	i = 0;
	ret = 0;
	if (init_filler(&f, &hm) < 0)
		return (-1);
	if (parse_board(&f) < 0)
		return (-1);
	make_filler_heatmap(&f, &hm);
	while (1)
	{
		if (i > 0 && parse_board(&f) < 0)
		{
			ret = -1;
			break ;
		}
		make_filler_heatmap(&f, &hm);
		if (handle_piece(&f, &hm) < 0)
		{
			ret = -1;
			break ;
		}
		i++;
	}
	free_char_2darr(f.board);
	free_int_2darr(hm.map);
	system("leaks rodrodri.filler");
	return (ret);
}

static int	init_filler(t_filler *f, t_heatmap *hm)
{
	ft_memset(f, 0, sizeof(*f));
	if (parse_playas(f) < 0)
		return (-1);
	if (find_line(&f->line, BOARD_SIZE_LN) < 0)
		return (-1);
	get_size(&f->line, &f->b_rows, &f->b_cols);
	f->board = alloc_char_2darr(f->b_rows, f->b_cols);
	if (!f->board)
		return (-1);
	if (hm_init(hm, f->b_rows, f->b_cols, 0) < 0)
		return (-1);
	return (0);
}
