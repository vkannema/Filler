/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 19:40:54 by vkannema          #+#    #+#             */
/*   Updated: 2017/03/09 10:14:57 by vkannema         ###   ########.fr       */
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
	char		*form_me;
	char		*form_en;
	int			start_en_x;
	int			start_en_y;
	int			start_me_x;
	int			start_me_y;
}				t_data;

void			get_env(t_data *data, t_piece *piece);
void			algo(t_data *data, t_piece *piece);
void			algo_player2(t_data *data, t_piece *piece);

#endif
