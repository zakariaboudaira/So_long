/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:07:44 by zboudair          #+#    #+#             */
/*   Updated: 2022/02/06 18:58:13 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_enemy(t_data	*data)
{
	data->en = 0;
	data->i1 = -1;
	while (++data->i1 < data->line)
	{
		data->j1 = -1;
		while (++data->j1 < data->column)
			move(data);
	}
}

void	move(t_data	*data)
{
	if (data->map[data->i1][data->j1] == 'Y'
		&& data->map[data->i1][data->j1 + data->dir[data->en]] != '1'
		&& data->map[data->i1][data->j1 + data->dir[data->en]] != 'C'
		&& data->map[data->i1][data->j1 + data->dir[data->en]] != 'Y'
		&& data->map[data->i1][data->j1 + data->dir[data->en]] != 'E')
	{
		move2(data);
	}
	else if (data->map[data->i1][data->j1] == 'Y' && data->dir[data->en] == 1)
		data->dir[data->en++] = -1;
	else if (data->map[data->i1][data->j1] == 'Y')
		data->dir[data->en++] = 1;
}

void	move2(t_data	*data)
{
	if (data->map[data->i1][data->j1 + data->dir[data->en]] == 'P')
	{
		write(1, "You Lose!\nGood Luck Next Time", 30);
		exit(0);
	}
	data->map[data->i1][data->j1] = '0';
	data->j1 += data->dir[data->en];
	data->map[data->i1][data->j1] = 'Y';
	if (data->dir[data->en] == 1)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->empty,
			(data->j1 - data->dir[data->en]) * 60, data->i1 * 40);
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->enemy1, data->j1 * 60, data->i1 * 40 - 3);
	}
	else if (data->dir[data->en] == -1)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->empty,
			(data->j1 - data->dir[data->en]) * 60, data->i1 * 40);
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->enemy2, data->j1 * 60, data->i1 * 40 - 3);
	}
	data->en++;
}
