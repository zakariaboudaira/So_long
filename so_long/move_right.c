/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:31:35 by zboudair          #+#    #+#             */
/*   Updated: 2022/02/06 19:00:13 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	move_right(t_data	*data)
{
	if (data->map[data->p1][data->p2 + 1] == '1')
		return (0);
	else if (data->map[data->p1][data->p2 + 1] == 'E')
	{
		if (data->coinscounter == data->counter)
		{
			write(1, "You win\nCongratulations ", 25);
			exit(1);
		}
	}
	else if (data->map[data->p1][data->p2 + 1] == 'C')
	{
		put_player(data);
		data->map[data->p1][data->p2] = 'P';
		data->counter++;
		data->movescounter++;
	}
	else
		p(data);
	return (0);
}

void	put_player(t_data	*data)
{
	data->map[data->p1][data->p2] = '0';
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->empty, data->p2 * 60, data->p1 * 40);
	data->p2++;
	data->p = 1;
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->empty,
		data->p2 * 60, data->p1 * 40);
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->player1, data->p2 * 60 + 15, data->p1 * 40);
}

void	p(t_data	*data)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->empty, data->p2 * 60, data->p1 * 40);
	data->map[data->p1][data->p2] = '0';
	data->p2++;
	if (data->map[data->p1][data->p2] == 'Y')
	{
		write(1, "You Lose!\nGood Luck Next Time", 30);
		exit(0);
	}
	data->map[data->p1][data->p2] = 'P';
	data->p = 1;
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->player1, data->p2 * 60 + 15, data->p1 * 40);
		data->movescounter++;
}
