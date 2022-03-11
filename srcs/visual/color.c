/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 22:37:24 by rodrodri          #+#    #+#             */
/*   Updated: 2022/03/11 12:26:38 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"
#include "libft.h"

static void	colorize_char(WINDOW *w, int win_row, int win_col, char ch, int color_pair);

void	init_colors()
{
	start_color();
	init_pair(PLAYA1_COLOR, COLOR_GREEN, COLOR_WHITE);
	init_pair(PLAYA1_COLOR2, COLOR_YELLOW, COLOR_BLUE);
	init_pair(PLAYA2_COLOR, COLOR_RED, COLOR_WHITE);
	init_pair(PLAYA2_COLOR2, COLOR_MAGENTA, COLOR_YELLOW);
	init_pair(NUM_COLOR, COLOR_BLACK, COLOR_WHITE);
}

void	colorize_line(WINDOW *w, char *line, int win_row)
{
	int	win_col;

	win_col = 0;
	while (win_col < (int)ft_strlen(line))
	{
		if (ft_isdigit(line[win_col]))
			colorize_char(w, win_row, win_col, line[win_col], NUM_COLOR);
		else if (line[win_col] == 'O')
			colorize_char(w, win_row, win_col, line[win_col], PLAYA1_COLOR);
		else if (line[win_col] == 'o')
			colorize_char(w, win_row, win_col, line[win_col], PLAYA1_COLOR2);
		else if (line[win_col] == 'X')
			colorize_char(w, win_row, win_col, line[win_col], PLAYA2_COLOR);
		else if (line[win_col] == 'x')
			colorize_char(w, win_row, win_col, line[win_col], PLAYA2_COLOR2);
		else
			colorize_char(w, win_row, win_col, line[win_col], NUM_COLOR);
		win_col++;
	}
}

static void	colorize_char(WINDOW *w, int win_row, int win_col, char ch, int color_pair)
{
	wattron(w, COLOR_PAIR(color_pair));
	mvwprintw(w, win_row, win_col, "%c", ch);
	wattroff(w, COLOR_PAIR(color_pair));
}