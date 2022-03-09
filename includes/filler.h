/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:24:50 by rodrodri          #+#    #+#             */
/*   Updated: 2022/03/09 21:02:38 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define PLAYA1			'O'
# define PLAYA2			'X'
/*
**# include <stdio.h> // <======= Delete me!!!
*/
/*
**	Type definitions
**	Add the following field to the struct, in order to log out to file:
**		FILE	*file;
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
	int		min_x;
	int		min_y;
}	t_filler;

/*
**	Prototypes
*/
int		parse_playas(t_filler *f);
int		parse_size(int fd, int *rows, int *cols);
int		parse_board(t_filler *f);
int		parse_piece(t_filler *f);

int		place_piece(t_filler *f);
int		make_heatmap(t_filler *f);
int		max_int(int a, int b);

char	**alloc_char_2darr(int rows, int cols);
int		**alloc_int_2darr(int rows, int cols);
void	free_char_2darr(char **arr);
void	free_int_2darr(int **arr);

#endif