/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 22:37:24 by rodrodri          #+#    #+#             */
/*   Updated: 2022/03/11 21:08:12 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"
#include "libft.h"

static void	colorize_char(t_visualizer *v, int win_row, int win_col, int pair);

void	init_colors(void)
{
	start_color();
	init_pair(PLAYA1_COLOR, COLOR_GREEN, COLOR_WHITE);
	init_pair(PLAYA1_COLOR2, COLOR_YELLOW, COLOR_BLUE);
	init_pair(PLAYA2_COLOR, COLOR_RED, COLOR_WHITE);
	init_pair(PLAYA2_COLOR2, COLOR_MAGENTA, COLOR_YELLOW);
	init_pair(NUM_COLOR, COLOR_BLACK, COLOR_WHITE);
}

void	colorize_b_line(t_visualizer *v, int win_row)
{
	int	win_col;

	win_col = 0;
	while (win_col < (int)ft_strlen(v->line))
	{
		if (ft_isdigit(v->line[win_col]))
			colorize_char(v, win_row, win_col, NUM_COLOR);
		else if (v->line[win_col] == 'O')
			colorize_char(v, win_row, win_col, PLAYA1_COLOR);
		else if (v->line[win_col] == 'o')
			colorize_char(v, win_row, win_col, PLAYA1_COLOR2);
		else if (v->line[win_col] == 'X')
			colorize_char(v, win_row, win_col, PLAYA2_COLOR);
		else if (v->line[win_col] == 'x')
			colorize_char(v, win_row, win_col, PLAYA2_COLOR2);
		else
			colorize_char(v, win_row, win_col, NUM_COLOR);
		win_col++;
	}
}

static void	colorize_char(t_visualizer *v, int win_row, int win_col, int pair)
{
	wattron(v->w_board, COLOR_PAIR(pair));
	mvwprintw(v->w_board, win_row, win_col, "%c", v->line[win_col]);
	wattroff(v->w_board, COLOR_PAIR(pair));
}
