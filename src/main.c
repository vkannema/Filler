/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 19:35:40 by vkannema          #+#    #+#             */
/*   Updated: 2017/03/09 10:23:17 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	init_data(t_data *data, t_piece *piece)
{
	data->size_x = 0;
	data->size_y = 0;
	piece->size_x = 0;
	piece->size_y = 0;
	data->map = NULL;
	data->player = 0;
	data->fd = 0;
}

void	init_player(t_data *data)
{
	char	*line;
	int		i;

	i = 0;
	get_next_line(0, &line);
	if (ft_strncmp(line, "$$$", 2) == 0)
	{
		while (line[i] && line[i] != 'p')
			i++;
		i++;
		data->player = ft_atoi(&line[i]);
	}
	if (data->player == 1)
	{
		data->form_me = "Oo";
		data->form_en = "Xx";
	}
	else if (data->player == 2)
	{
		data->form_me = "Xx";
		data->form_en = "Oo";
	}
}

int		main(void)
{
	t_data	*data;
	t_piece	*piece;
	int		fd;

	fd = open("test", O_RDWR);
	data = malloc(sizeof(t_data));
	piece = malloc(sizeof(t_piece));
	init_data(data, piece);
	data->fd = open("return", O_RDWR);
	init_player(data);
	// while (1)
	// {
		get_env(data, piece);
		ft_printf("%d\n", data->player);
		algo(data, piece);
	// }
	close(fd);
	return (0);
}
