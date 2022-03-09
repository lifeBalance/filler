/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logging.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 10:06:21 by rodrodri          #+#    #+#             */
/*   Updated: 2022/03/09 15:23:29 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGING_H
# define LOGGING_H

#include <fcntl.h>
#include "filler.h"

void	flog(int fd, const char *s);
void	flog_playa(int fd, char playa);
void	flog_size(int fd, const char *str, int rows, int cols);
void	flog_char_matrix(int fd, char **str, int rows, int cols);
void	flog_heatmap(int fd, int **arr, int rows, int cols);

#endif