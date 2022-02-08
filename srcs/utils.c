/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:07:35 by rodrodri          #+#    #+#             */
/*   Updated: 2022/02/08 17:19:12 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

int	get_size(char **ln, int *rows, int *cols)
{
	int		advance;

	advance = parse_digits(*ln, rows);
	parse_digits(*ln + advance, cols);
	ft_strdel(ln);
	return (1);
}

/*
**	It parses its 'str' argument (the address of a string), searching for
**	digits, which are stored in an 'int' variable returned at the end.
*/
int	parse_digits(char *line, int *n)
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

/*
**	It fast-forwards to the line which contains its 'str' argument.
**	Return values:
**		- If the line is found, 1.
**		- If the line is NOT found, 0.
**		- If the END LINE ("fin") found, -1.
*/
int	find_line(char **ln, const char *str)
{
	int		ret;

	ret = get_next_line(STDIN_FILENO, ln);
	while (ret > 0)
	{
		if (ft_strstr(*ln, str))
			return (1);
		else if (ft_strstr(*ln, "fin"))
		{
			ft_strdel(ln);
			return (-1);
		}
		else
		{
			ft_strdel(ln);
			ret = get_next_line(STDIN_FILENO, ln);
		}
	}
	return (0);
}

/*
**	It skips a given number of lines, freeing allocated lines along the way.
*/
int	skip_lines(t_filler *f, int n)
{
	while (n--)
	{
		if (get_next_line(STDIN_FILENO, &f->line) <= 0)
			return (-1);
		ft_strdel(&f->line);
	}
	return (1);
}

/*
**	It reads the line with the last play, checking if its value is "[0, 0]"
**	It also determines the player that played last, setting the 'last_move'
**	field accordingly.
**	Regardless of the player, it returns 0 if the last play was "[0, 0]",
**	and 1 otherwise.
*/
int		check_play(char **ln)
{
	int		play;

	get_next_line(STDIN_FILENO, ln);
	if (ft_strstr(*ln, "[0, 0]"))
		play = 0;
	else
		play = 1;
	if (play == 0) // <=================================== delete me!!!!
		ft_printf("other guy moved [0, 0]\n");
	ft_strdel(ln);
	return (play);
}

/*
**	It prints the token and releases it when done. It doesn't return anything.
*/
void	print_char2darr(char **str, int rows, int cols)
{
	int		i;
	int		j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
			ft_printf("%c", str[i][j++]);
		ft_putchar('\n');
		i++;
	}
}

void	toggle_next(t_filler *f)
{
	if (f->next == PLAYA1)
		f->next = PLAYA2;
	else
		f->next = PLAYA1;
}

char **alloc_char_2darr(int rows, int cols)
{
	char **arr;
	int i;

	arr = (char **)malloc(sizeof(char *) * rows);
	if (!arr)
		return (0);
	ft_memset(arr, 0, sizeof(char *) * rows);
	i = 0;
	while (i < rows)
	{
		arr[i] = ft_strnew(cols);
		if (!arr[i])
		{
			free_char_2darr(arr, rows);
			return (0);
		}
		i++;
	}
	arr[i] = 0;
	return (arr);
}

void	free_char_2darr(char **arr, int rows)
{
	int	i;

	i = 0;
	while (arr[i] && i < rows)
	{
		ft_strdel(arr + i);
		i++;
	}
	ft_memdel((void **)arr);
}