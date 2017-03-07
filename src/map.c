/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:04:07 by vkannema          #+#    #+#             */
/*   Updated: 2017/03/07 18:43:59 by vkannemacher     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Filler.h"

void	get_map_size(char *line, t_map *map)
{
	int	i;

	i = 0;
	while (!ft_isdigit(line[i]))
		i++;
	map->size_y = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	while (!ft_isdigit(line[i]))
		i++;
	map->size_x = ft_atoi(&line[i]);
}

void	get_piece_size(char *line, t_piece *piece)
{
	int	i;

	i = 0;
	while (!ft_isdigit(line[i]))
		i++;
	piece->size_y = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	while (!ft_isdigit(line[i]))
		i++;
	piece->size_x = ft_atoi(&line[i]);
}

void	get_env(t_map *map, t_piece *piece)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		if (ft_strncmp(line, "Plateau", 6) == 0)
		{
			get_map_size(line, map);
		}
		else if (ft_strncmp(line, "Piece", 4) == 0)
		{
			get_piece_size(line, piece);
		}
		else
			ft_strdel(&line);
	}
}
