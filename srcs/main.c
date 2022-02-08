/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:22:48 by rodrodri          #+#    #+#             */
/*   Updated: 2022/02/08 17:10:10 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

int		get_our_playa(t_filler *f);

int	main(void)
{
	t_filler	f;

	ft_memset(&f, 0, sizeof(f));
	if (get_our_playa(&f) <= 0)
		return (-1);
	if (find_line(&f.line, BOARD_SIZE_LN))
		get_size(&f.line, &f.b_rows, &f.b_cols);
	else
		return (-1);
	if (alloc_board(&f) < 0 || parse_board(&f) < 0)
		return (-1);
	f.next = PLAYA1;
	while (1)
	{
		print_char2darr(f.board, f.b_rows, f.b_cols); // <=== delete me!!!!!
		if (handle_piece(&f) < 0)
			break ;
		if (parse_board(&f) < 0)
			break ;
	}
	free_char_2darr(f.board, f.b_rows);
	system("leaks rodrodri.filler");
	return (0);
}

/*
**	It finds the line starting with '$$$ exec p1', and checks if it
**	contains our player name. If so, we're player 1, otherwise we're player 2.
**	(It could be refactored to also extract both player names and store them
**	in dedicated fields of the t_filler structure; can be used for visualize).
*/
int	get_our_playa(t_filler *f)
{
	int	ret;

	ret = find_line(&f->line, WHOS_PLAYA1_LN);
	if (ret < 0)
		return (-1);
	else if (ret == 0)
		return (0);
	if (ft_strstr(f->line, AUTHOR))
	{
		f->our_playa = PLAYA1;
		f->other_playa = PLAYA2;
	}
	else
	{
		f->our_playa = PLAYA2;
		f->other_playa = PLAYA1;
	}
	ft_strdel(&f->line);
	return (1);
}
