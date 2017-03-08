/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 19:40:54 by vkannema          #+#    #+#             */
/*   Updated: 2017/03/08 14:51:39 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <libftprintf.h>
# include <libft.h>

typedef struct	s_piece
{
	int			size_x;
	int			size_y;
	char		**coord;
}				t_piece;

typedef struct	s_data
{
	int			size_x;
	int			size_y;
	char		**map;
	int			player;
	int			fd;
}				t_data;

void			get_env(t_data *data, t_piece *piece);

#endif
