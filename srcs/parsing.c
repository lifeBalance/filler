/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:03:50 by rodrodri          #+#    #+#             */
/*   Updated: 2022/03/09 21:00:05 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"
/*
** #include "logging.h"
*/
static int	parse_num(int fd, char n);

/*
**	It parses the board, a 2d array of characters, nothing special.
**	The only thing to mention is the first line after the declarations:
**	Its purpose is to move the file cursor passed the last position.
*/
int	parse_board(t_filler *f)
{
	int		i;
	int		j;
	char	ch[1];

	read(STDIN_FILENO, ch, 1);
	while (!ft_strchr("XxOo.", ch[0]))
		read(STDIN_FILENO, ch, 1);
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
			read(STDIN_FILENO, ch, 1);
		}
		i++;
	}
	return (0);
}

int	parse_piece(t_filler *f)
{
	int		i;
	int		j;
	char	ch;

	if (parse_size(STDIN_FILENO, &f->p_rows, &f->p_cols) < 0)
		return (-1);
	f->piece = alloc_char_2darr(f->p_rows, f->p_cols);
	if (!f->piece)
		return (-1);
	i = 0;
	while (i < f->p_rows)
	{
		j = 0;
		while (j < f->p_cols)
		{
			read(STDIN_FILENO, &ch, 1);
			if (ft_strchr("*.", ch))
			{
				f->piece[i][j] = ch;
				j++;
			}
		}
		i++;
	}
	return (0);
}

int	parse_playas(t_filler *f)
{
	char	ch;

	ch = '*';
	while (!ft_isdigit(ch))
		read(STDIN_FILENO, &ch, 1);
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
