/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:07:35 by rodrodri          #+#    #+#             */
/*   Updated: 2022/02/06 17:03:52 by rodrodri         ###   ########.fr       */
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
		ft_strdel(&line);
		ret = get_next_line(0, &line);
	}
	if (ret <= 0)
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

int		check_play(void)
{
	char	*line;
	int		play;

	get_next_line(0, &line);
	if (ft_strstr(line, "[0, 0]"))
		play = 0;
	else
		play = 1;
	ft_strdel(&line);
	return (play);
}

/*
**	It prints a string in a matrix format, according to its 'rows' and 'cols'
**	arguments. It doesn't return anything.
*/
void	print_matrix(char *s, int rows, int cols)
{
	int		i;

	i = 0;
	while (s[i] && i < rows * cols)
	{
		ft_printf("%c", s[i]);
		if (i % cols == cols - 1)
			ft_putchar('\n');
		i++;
	}
}
