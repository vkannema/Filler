/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 15:00:47 by vkannema          #+#    #+#             */
/*   Updated: 2017/03/09 10:21:22 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_start_ennemy(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == data->form_en[0] ||
				data->map[y][x] == data->form_en[1])
			{
				data->start_en_x = x;
				data->start_en_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	get_start_pos(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == data->form_me[0] ||
				data->map[y][x] == data->form_me[1])
			{
				data->start_me_x = x;
				data->start_me_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	algo_player1(t_data *data, t_piece *piece)
{
	(void)piece;
	get_start_ennemy(data);
	get_start_pos(data);
	// shorter_pos();
	// is_placable();
	return ;
}

void	algo(t_data *data, t_piece *piece)
{
	if (data->player == 1)
		algo_player1(data, piece);
	ft_printf("smex %d smey %d senx %d seny %d form_me %s form_en %s\n", data->start_me_x, data->start_me_y, data->start_en_x, data->start_en_y, data->form_me, data->form_en);
	// else if (data->player == 2)
	// 	algo_player2(data, piece);
}
