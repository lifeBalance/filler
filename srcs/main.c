/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:22:48 by rodrodri          #+#    #+#             */
/*   Updated: 2022/03/09 16:16:13 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"
#include "logging.h"

static int	init_filler(t_filler *f);

int	main(void)
{
	t_filler	f;// try to allocate it in the heap??
	int			ret;

	ret = 1;
	if (init_filler(&f) < 0)// find player and set all fields in 'f' to ZERO
		return (-1);
	while (ret > 0)
	{
		flog(f.file, "---board---\n");// <======= Don't forget to delete me!!!
		if (parse_board(&f) < 0 || parse_piece(&f) < 0)
			break ;
		if (place_piece(&f) == 0)
			ft_printf("%d, %d\n", f.y, f.x);
		else
		{
			ft_putstr("0 0\n");
			ret = -1;
		}
		free_char_2darr(f.piece);
		free(f.piece);
	}
	close(f.file);
	system("leaks rodrodri.filler"); // export MallocStackLogging=1
	return (ret);
}

static int	init_filler(t_filler *f)
{
	ft_bzero(f, sizeof(*f));
	f->file = open ("file.txt", O_CREAT | O_TRUNC | O_WRONLY);// <=======Don't forget to delete this!!!
	if (parse_playas(f) < 0)
		return (-1);
	flog_playa(f->file, f->our_playa);// <=======Don't forget to delete this!!!
	parse_size(f->fd, &f->b_rows, &f->b_cols);
	flog_size(f->file, "Board size: ", f->b_rows, f->b_cols);// <=======Don't forget to delete this!!!
	f->board = alloc_char_2darr(f->b_rows, f->b_cols);
	if (!f->board)
		return (-1);
	f->heatmap = alloc_int_2darr(f->b_rows, f->b_cols);
	if (!f->heatmap)
		return (-1);
	return (0);
}
