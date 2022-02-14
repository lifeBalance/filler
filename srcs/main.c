/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:22:48 by rodrodri          #+#    #+#             */
/*   Updated: 2022/02/14 01:05:14 by rodrodri         ###   ########.fr       */
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

	ret = 0;
	if (init_filler(&f, &hm) < 0)
		return (-1);
	while (1)
	{
		if (parse_board(&f, &hm) < 0)
			break ;
		else if (handle_piece(&f, &hm) < 0)
			break ;
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
	// ft_printf("board: %d %d\n", f->b_rows, f->b_cols);// delete me!!
	f->board = alloc_char_2darr(f->b_rows, f->b_cols);
	if (!f->board)
		return (-1);
	if (hm_init(hm, f->b_rows, f->b_cols, 0) < 0)
		return (-1);
	return (0);
}
