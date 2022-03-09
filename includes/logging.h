/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logging.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 10:06:21 by rodrodri          #+#    #+#             */
/*   Updated: 2022/03/09 19:54:03 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGING_H
# define LOGGING_H

#include <fcntl.h>
#include <stdio.h>
#include "filler.h"

void	flog_char_matrix(FILE *file, char **str, int rows, int cols, const char *s);
void	flog_heatmap(FILE *file, int **arr, int rows, int cols);

#endif