/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 19:35:40 by vkannema          #+#    #+#             */
/*   Updated: 2017/03/07 19:21:20 by vkannemacher     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Filler.h>

void	init_data(t_map *map, t_piece *piece)
{
	map->size_x = 0;
	map->size_y = 0;
	piece->size_x = 0;
	piece->size_y = 0;
	map->array = NULL;
}

int	main(void)
{
	t_map	*map;
	t_piece	*piece;

	map = malloc(sizeof(t_map));
	piece = malloc(sizeof(t_piece));
	init_data(map, piece);
	while (1)
	{
		get_env(map, piece);
	}
	ft_printf("msx %d msy %d psx %d psy%d\n", map->size_x, map->size_y, piece->size_x, piece->size_y);
	return (0);
}
