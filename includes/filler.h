/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:24:50 by rodrodri          #+#    #+#             */
/*   Updated: 2022/03/09 15:56:49 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define PLAYA1			'O'
# define PLAYA2			'X'

/*
**	Type definitions
*/
typedef struct s_filler
{
	char	**board;
	char	**piece;
	char	*line;
	int		**heatmap;
	char	our_playa;
	char	other_playa;
	int		b_rows;
	int		b_cols;
	int		p_rows;
	int		p_cols;
	int		y;
	int		x;
	int		min;
	int		file;
	int		fd;
}	t_filler;

/*
**	Prototypes
*/
int		parse_playas(t_filler *f);
int		parse_size(int fd, int *rows, int *cols);
int		parse_board(t_filler *f);
int		parse_piece(t_filler *f);

int		place_piece(t_filler *f);
// int		parse_board(t_filler *f, t_heatmap *hm);
// int		place_piece(t_filler *f, t_heatmap *hm);
// int		handle_piece(t_filler *f, t_heatmap *hm);

char	**alloc_char_2darr(int rows, int cols);
void	free_char_2darr(char **arr);
// int		find_line(char **ln, const char *str);
// int		skip_lines(char **str, int n);
// void	print_char2darr(char **str);

// int		make_filler_heatmap(t_filler *f, t_heatmap *hm);
// void	print_filler_heatmap(t_heatmap *hm);
int		make_heatmap(t_filler *f);
int		max_int(int a, int b);
int 	**alloc_int_2darr(int rows, int cols);
void	free_int_2darr(int **arr);

#endif