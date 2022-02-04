/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:22:48 by rodrodri          #+#    #+#             */
/*   Updated: 2022/02/04 13:05:36 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"
#include <stdio.h>

static void	get_playa(int *playa);
static void	get_size(int *rows, int *cols);
static int	parse_digits(char **line);

int	main(void)
{
	int		playa;
	int		rows;
	int		cols;
	// char	*board;

	// ft_printf("Buf: %d\n", BUFF_SIZE);
	get_playa(&playa);
	ft_printf("you're playa #%d!\n", playa);
	get_size(&rows, & cols);
	ft_printf("rows: %d, cols: %d\n", rows, cols);
	ft_printf("0 0");
	system("leaks rodrodri.filler");
	return (0);
}

static void	get_playa(int *playa)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_strncmp(line, "$$$", 3) == 0)
			break ;
		ft_strdel(&line);
	}
	if (ft_strnequ(ft_strstr(line, AUTHOR), AUTHOR, ft_strlen(AUTHOR)))
		*playa = 1;
	else
		*playa = 2;
	ft_strdel(&line);
}

static void	get_size(int *rows, int *cols)
{
	char	*line;
	char	*line_cpy;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_strncmp(line, "Plateau", ft_strlen("Plateau")) == 0)
			break ;
		ft_strdel(&line);
	}
	line_cpy = line;
	*rows = parse_digits(&line);
	*cols = parse_digits(&line);
	ft_strdel(&line_cpy);
}

static int	parse_digits(char **line)
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
