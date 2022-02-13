/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:22:48 by rodrodri          #+#    #+#             */
/*   Updated: 2022/02/13 14:50:28 by rodrodri         ###   ########.fr       */
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

	if (init_filler(&f, &hm) < 0)
		return (-1);
	// ft_printf("We're |%c|\n", f.our_playa);
	while (get_next_line(STDIN_FILENO, &f.line) > 0)
	{
		if (ft_strstr(f.line, FIRST_BOARD_LN))
		{
			parse_board(&f);
			make_filler_heatmap(&f, &hm);
			// print_char2darr(f.board); // <=== delete me!!!!!
			// print_filler_heatmap(&hm); // <=== delete me!!!!!
		}
		else if (ft_strstr(f.line, PIECE_SIZE_LN))
		{
			if (!handle_piece(&f, &hm))
				break ;
			ret = check_play(&f);// this puts another line in the heap!!
			if (ret < 0)
			{
				ft_strdel(&f.line);// which we delete here ('== fin')
				break ;
			}
			else if (ret > 0)
				ft_strdel(&f.line);// or here (another Plateau)
			else if (!handle_piece(&f, &hm))
				break ;
		}
		else
			ft_strdel(&f.line);
	}
	free_char_2darr(f.board);
	free_int_2darr(hm.map);
	system("leaks rodrodri.filler");
	return (0);
}

static int	init_filler(t_filler *f, t_heatmap *hm)
{
	ft_memset(f, 0, sizeof(*f));
	if (get_our_playa(f) <= 0)
		return (-1);
	if (find_line(&f->line, BOARD_SIZE_LN) <= 0)
		return (-1);
	if (get_size(&f->line, &f->b_rows, &f->b_cols) < 0)
		return (-1);
	f->board = alloc_char_2darr(f->b_rows, f->b_cols);
	if (!f->board)
		return (-1);
	if (hm_init(hm, f->b_rows, f->b_cols, 0) < 0)
		return (-1);
	f->next_turn = PLAYA1;
	return (0);
}
