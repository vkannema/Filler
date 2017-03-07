/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 19:40:54 by vkannema          #+#    #+#             */
/*   Updated: 2017/03/07 19:17:53 by vkannemacher     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <libftprintf.h>
# include <libft.h>

typedef struct s_piece
{
	int			size_x;
	int			size_y;
}				t_piece;

typedef struct		s_map
{
	char			*map;
	int			size_x;
	int			size_y;
	char			**array;
}				t_map;

t_map			*get_map();
t_piece			*get_piece();
void				get_env(t_map *map, t_piece *piece);

#endif
