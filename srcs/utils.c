/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:07:35 by rodrodri          #+#    #+#             */
/*   Updated: 2022/02/06 22:44:17 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

/*
**	It parses its 'str' argument (the address of a string), searching for
**	digits, which are stored in an 'int' variable returned at the end.
*/
int	parse_digits(char **line)
{
	int	n;

	while (!ft_isdigit(**line))
		(*line)++;
	n = 0;
	while (**line && ft_isdigit(**line))
	{
		n = n * 10 + (**line - '0');
		(*line)++;
	}
	return (n);
}

/*
**	It fast-forwards to the line which contains its 'str' argument.
**	It returns that line if found, zero (NULL) otherwise.
*/
char	*find_line(const char *str)
{
	int		ret;
	char	*line;

	ret = get_next_line(0, &line);
	while (ret > 0 && !ft_strstr(line, str))
	{
		if (ft_strstr(line, "fin"))
			break ;
		ft_strdel(&line);
		ret = get_next_line(0, &line);
	}
	if (ret <= 0 || ft_strstr(line, "fin"))
	{
		ft_strdel(&line);
		return (0);
	}
	return (line);
}

void	skip_lines(int n)
{
	char	*line;

	while (n--)
	{
		get_next_line(0, &line);
		ft_strdel(&line);
	}
}

/*
**	It reads the line with the last play, checking if its value is "[0, 0]"
**	It also determines the player that played last, setting the 'last_move'
**	field accordingly.
**	Regardless of the player, it returns 0 if the last play was "[0, 0]",
**	and 1 otherwise.
*/
int		check_play(t_filler *f)
{
	char	*line;
	char	*line_cpy;
	int		play;

	get_next_line(0, &line);
	line_cpy = line;
	if (ft_strstr(line, "[0, 0]"))
		play = 0;
	else
		play = 1;
	(void)f;
	if (play == 0)
		ft_printf("other guy moved [0, 0]\n");
	// line = ft_strchr(line, '(') + 1;
	// if (*line == 'O')
	// 	f->next = 1;
	// else
	// 	f->next = 2;
	ft_strdel(&line_cpy);
	return (play);
}

/*
**	It prints the token and releases it when done. It doesn't return anything.
*/
void	print_token(t_filler *f)
{
	int		i;

	i = 0;
	while (f->token[i] && i < f->token_rows * f->token_cols)
	{
		ft_printf("%c", f->token[i]);
		if (i % f->token_cols == f->token_cols - 1)
			ft_putchar('\n');
		i++;
	}
	ft_strdel(&f->token);
}

/*
**	It prints the board. It doesn't return anything.
*/
void	print_board(t_filler *f)
{
	int		i;

	i = 0;
	while (f->board[i] && i < f->rows * f->cols)
	{
		ft_printf("%c", f->board[i]);
		if (i % f->cols == f->cols - 1)
			ft_putchar('\n');
		i++;
	}
}

void	toggle_next(t_filler *f)
{
	if (f->next == 1)
		f->next = 2;
	else
		f->next = 1;
}
