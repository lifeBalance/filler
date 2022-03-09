/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logging.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 10:06:21 by rodrodri          #+#    #+#             */
/*   Updated: 2022/03/09 10:09:38 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGING_H
# define LOGGING_H

#include <fcntl.h>
#include "filler.h"
#include "heatmap.h"

void	fprint_playa(t_filler *f);
void	fprint_char2darr(t_filler *f, char **str, int rows, int cols);
void	fprint_size(t_filler *f, const char *str, int rows, int cols);

#endif