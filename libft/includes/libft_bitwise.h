/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bitwise.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:14:45 by rodrodri          #+#    #+#             */
/*   Updated: 2022/02/02 16:57:10 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_BITWISE_H
# define LIBFT_BITWISE_H

/*
** Allowed headers.
*/
# include <stdint.h>

/*
**	Function Prototypes.
*/
uint16_t	test_bit(uint8_t pos, uint16_t val);
void		set_bit(uint8_t pos, uint16_t *val);
void		clear_bit(uint8_t pos, uint16_t *val);
void		toggle_bit(uint8_t pos, uint16_t *val);
uint16_t	create_mask(uint8_t offset);
uint16_t	msk_grp(uint8_t width, uint8_t pos);
uint16_t	read_group(uint8_t pos, uint8_t width, uint16_t val);
uint16_t	write_group(uint8_t pos, uint8_t width, uint16_t val, uint8_t grp);

#endif