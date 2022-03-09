/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:22:48 by rodrodri          #+#    #+#             */
/*   Updated: 2022/03/09 20:22:16 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"
#include "logging.h"

static int	init_filler(t_filler *f);

int	main(void)
{
	t_filler	f;
	int			ret;

	ret = 1;
	if (init_filler(&f) < 0)
		return (-1);
	f.file = fopen("file.txt", "w+");// <=======Don't forget to delete this!!!
	fprintf(f.file, "Our playa: %c, other playa: %c\n", f.our_playa, f.other_playa);// <===Delete this!!!
	while (ret > 0)
	{
		if (parse_board(&f) < 0 || parse_piece(&f) < 0)
			break ;
		flog_char_matrix(f.file, f.board, f.b_rows, f.b_cols, "Board");// <========== delete me!!!!
		flog_char_matrix(f.file, f.piece, f.p_rows, f.p_cols, "Piece");// <========== delete me!!!!
		if (place_piece(&f) == 0)
			ft_printf("%d %d\n", f.min_y, f.min_x);
		else
		{
			ft_putstr("0 0\n");
			ret = -1;
		}
		free_char_2darr(f.piece);
		free(f.piece);
	}
	free_int_2darr(f.heatmap);
	free(f.heatmap);
	fclose(f.file);
	system("leaks rodrodri.filler"); // export MallocStackLogging=1
	return (ret);
}

static int	init_filler(t_filler *f)
{
	ft_bzero(f, sizeof(*f));
	if (parse_playas(f) < 0)
		return (-1);
	parse_size(f->fd, &f->b_rows, &f->b_cols);
	f->board = alloc_char_2darr(f->b_rows, f->b_cols);
	if (!f->board)
		return (-1);
	f->heatmap = alloc_int_2darr(f->b_rows, f->b_cols);
	if (!f->heatmap)
		return (-1);
	return (0);
}
