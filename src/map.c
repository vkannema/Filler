/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:04:07 by vkannema          #+#    #+#             */
/*   Updated: 2017/03/08 14:52:35 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Filler.h"

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

int		get_map(char *line, t_data *data)
{
	int	y;

	y = 0;
	get_next_line(0, &line);
	ft_strdel(&line);
	data->map = (char **)malloc(sizeof(char *) * data->size_y);
	while (y < data->size_y && data->size_y - 1)
	{
		get_next_line(0, &line);
		data->map[y] = (char *)malloc(sizeof(char) * data->size_x + 1);
		data->map[y] = ft_strcpy(data->map[y], line);
		y++;
	}
	ft_strdel(&line);
	return (1);
}

void	get_map_size(char *line, t_data *data)
{
	int	i;

	i = 0;
	while (!ft_isdigit(line[i]))
		i++;
	data->size_y = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	while (!ft_isdigit(line[i]))
		i++;
	data->size_x = ft_atoi(&line[i]);
	get_map(line, data);
}

void	get_piece(char *line, t_piece *piece)
{
	int	y;

	y = 0;
	piece->coord = (char **)malloc(sizeof(char *) * piece->size_y);
	while (y < piece->size_y && piece->size_y - 1)
	{
		get_next_line(0, &line);
		piece->coord[y] = ft_strdup((const char *)(&line[0]));
		y++;
	}
}

void	get_env(t_data *data, t_piece *piece)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		if (ft_strncmp(line, "Plateau", 6) == 0)
		{
			get_map_size(line, data);
		}
		else if (ft_strncmp(line, "Piece", 4) == 0)
		{
			get_piece_size(line, piece);
			get_piece(line, piece);
		}
	}
}
