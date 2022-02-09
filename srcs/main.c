/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:22:48 by rodrodri          #+#    #+#             */
/*   Updated: 2022/02/09 18:21:01 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

static int	init_filler(t_filler *f);

int	main(void)
{
	t_filler	f;

	if (init_filler(&f) < 0)
		return (-1);
	print_char2darr(f.board); // <=== delete me!!!!!
	while (get_next_line(STDIN_FILENO, &f.line) > 0)
	{
		if (ft_strstr(f.line, PIECE_SIZE_LN))
			handle_piece(&f);
		else if (ft_strstr(f.line, LAST_MOVE_LN))
		{
			if (check_play(&f) < 0)
				break ;
		}
		else if (ft_strstr(f.line, FIRST_BOARD_LN))
		{
			parse_board(&f);
			print_char2darr(f.board); // <=== delete me!!!!!
		}
	}
	free_char_2darr(f.board);
	system("leaks rodrodri.filler");
	return (0);
}

static int	init_filler(t_filler *f)
{
	ft_memset(f, 0, sizeof(*f));
	if (get_our_playa(f) <= 0)
		return (-1);
	if (find_line(&f->line, BOARD_SIZE_LN) <= 0)
		return (-1);
	if (get_size(&f->line, &f->b_rows, &f->b_cols) < 0)
		return (-1);
	if (find_line(&f->line, FIRST_BOARD_LN) <= 0)
		return (-1);
	f->board = alloc_char_2darr(f->b_rows, f->b_cols);
	if (!f->board)
		return (-1);
	if (parse_board(f) < 0)
		return (-1);
	f->next_turn = PLAYA1;
	return (0);
}
