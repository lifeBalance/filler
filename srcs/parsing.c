/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:03:50 by rodrodri          #+#    #+#             */
/*   Updated: 2022/03/09 13:27:53 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"
#include "logging.h"

static int	parse_num(int fd, char n);

int	parse_board(t_filler *f)
{
	int		i;
	int		j;
	char	ch[1];

	read(f->fd, ch, 1); // to get the party started!
	while (!ft_strchr("XxOo.", ch[0]))
		read(f->fd, ch, 1);
	i = 0;
	while (i < f->b_rows)
	{
		j = 0;
		while (j < f->b_cols)
		{
			if (ft_strchr("XxOo.", ch[0]))
			{
				f->board[i][j] = ch[0];
				j++;
			}
			read(f->fd, ch, 1);
		}
		i++;
	}
	flog_char_matrix(f->file, f->board, f->b_rows, f->b_cols);// <========== delete me!!!!
	return (0);
}

int	parse_piece(t_filler *f)
{
	int		i;
	int		j;
	char	ch;

	flog(f->file, "---piece---\n");// <======= Don't forget to delete me!!!
	if (parse_size(f->fd, &f->p_rows, &f->p_cols) < 0)
		return (-1);
	flog_size(f->file, "Piece size: ", f->p_rows, f->p_cols);// <=======Don't forget to delete this!!!
	f->piece = alloc_char_2darr(f->p_rows, f->p_cols);
	if (!f->piece)
		return (-1);
	flog(f->file, "---parsing---\n");// <======= Don't forget to delete me!!!
	i = 0;
	while (i < f->p_rows)
	{
		j = 0;
		while (j < f->p_cols)
		{
			read(f->fd, &ch, 1);
			if (ft_strchr("*.", ch))
			{
				f->piece[i][j] = ch;
				j++;
			}
		}
		i++;
	}
	flog_char_matrix(f->file, f->piece, f->p_rows, f->p_cols);// <========== delete me!!!!
	flog(f->file, "---piece parsed---\n");// <======= Don't forget to delete me!!!
	return (0);
}

int	parse_playas(t_filler *f)
{
	char	ch;

	ch = '*';
	while (!ft_isdigit(ch))
		read(f->fd, &ch, 1);
	if (ch == '1')
	{
		f->our_playa = PLAYA1;
		f->other_playa = PLAYA2;
	}
	else if (ch == '2')
	{
		f->our_playa = PLAYA2;
		f->other_playa = PLAYA1;
	}
	else
		return (-1);
	return (0);
}

int	parse_size(int fd, int *rows, int *cols)
{
	char	ch;

	read(fd, &ch, 1);
	while (!ft_isdigit(ch))
		read(fd, &ch, 1);
	*rows = parse_num(fd, ch);
	read(fd, &ch, 1);
	while (!ft_isdigit(ch))
		read(fd, &ch, 1);
	*cols = parse_num(fd, ch);
	if (*rows <= 0 || *cols <= 0)
		return (-1);
	return (0);
}

static int	parse_num(int fd, char digit)
{
	char	ch;
	int		n;

	ch = digit;
	n = 0;
	while (ft_isdigit(ch))
	{
		n = n * 10 + (ch - '0');
		read(fd, &ch, 1);
	}
	return (n);
}
