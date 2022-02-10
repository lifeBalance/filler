/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:45:52 by rodrodri          #+#    #+#             */
/*   Updated: 2022/02/10 22:46:01 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEATMAP_H
# define HEATMAP_H

/*
**	Type definitions
*/
typedef	struct s_heatmap
{
	int	**map;
	int	rows;
	int	cols;
	int	r;
	int	c;
}	t_heatmap;

/*
**	Function prototypes
*/
int		hm_init(t_heatmap **hm, int rows, int cols, int val);
int		make_heatmap(t_heatmap *hm);
int		max_int(int a, int b);
int 	**alloc_int_2darr(int rows, int cols);
void	free_int_2darr(int **arr, int rows);

#endif