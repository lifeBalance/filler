/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 13:08:45 by rodrodri          #+#    #+#             */
/*   Updated: 2022/03/11 15:08:37 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "visual.h"

static int	parse_digits(char *line, int *n);
static void	parse_size(char **ln, int *rows, int *cols);

void	parse_board_size(t_visualizer *v)
{
	parse_size(&v->line, &v->b_rows, &v->b_cols);
}
/*
**	It passes its 'str' argument (the address of a string), to the 
**	'parse_digits' function, which returns an 'int' value that will
**	be assigned to the 'rows' and 'cols' parameters.
**	It DELETES the string at the end, and returns '1'.
*/
void	parse_size(char **ln, int *rows, int *cols)
{
	int		advance;

	advance = parse_digits(*ln, rows);
	parse_digits(*ln + advance, cols);
	ft_strdel(ln);
}

/*
**	It parses its 'str' argument, searching for digits, which
**	are stored in an 'int' variable returned at the end.
*/
static int	parse_digits(char *line, int *n)
{
	int	i;

	i = 0;
	while (!ft_isdigit(line[i]))
		i++;
	*n = 0;
	while (line[i] && ft_isdigit(line[i]))
	{
		*n = *n * 10 + (line[i] - '0');
		i++;
	}
	return (i);
}

void	parse_score(t_visualizer *v)
{
	v->score1 = 0;
	v->score2 = 0;
	if (find_line(v->fd, &v->line, END_GAME_LN) == 0)
		parse_digits(v->line, &v->score1);
	ft_strdel(&v->line);
	if (find_line(v->fd, &v->line, END_GAME_LN) == 0)
		parse_digits(v->line, &v->score2);
	ft_strdel(&v->line);
}

int	find_line(int fd, char **ln, const char *str)
{
	int		ret;

	ret = get_next_line(fd, ln);
	while (ret > 0)
	{
		if (ft_strstr(*ln, str))
			return (0);
		else
		{
			ft_strdel(ln);
			ret = get_next_line(fd, ln);
		}
	}
	return (-1);
}