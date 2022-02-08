/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:38:48 by zboudair          #+#    #+#             */
/*   Updated: 2022/02/06 18:58:02 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	move_down(t_data	*data)
{
	int	i;
	int	j;

	if (data->map[data->p1 + 1][data->p2] == '1')
		return (0);
	else if (data->map[data->p1 + 1][data->p2] == 'C')
	{
		put_player3(data);
		data->map[data->p1][data->p2] = 'P';
		data->counter++;
		data->movescounter++;
	}
	else if (data->map[data->p1 + 1][data->p2] == 'E')
	{
		if (data->coinscounter == data->counter)
		{
			write(1, "You win\nCongratulations ", 25);
			exit(1);
		}
	}
	else
		p3(data);
	return (0);
}

void	put_player3(t_data	*data)
{
	data->map[data->p1][data->p2] = '0';
	mlx_put_image_to_window(data->mlx,
		data->mlx_win, data->empty, data->p2 * 60, data->p1 * 40);
	data->p1++;
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->empty, data->p2 * 60, data->p1 * 40);
	if (data->p == 1)
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->player1, data->p2 * 60 + 15, data->p1 * 40);
	else if (data->p == 0)
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->player2, data->p2 * 60 + 15, data->p1 * 40);
}

void	p3(t_data	*data)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->empty, data->p2 * 60, data->p1 * 40);
	data->map[data->p1][data->p2] = '0';
	data->p1++;
	if (data->map[data->p1][data->p2] == 'Y')
	{
		write(1, "You Lose!\nGood Luck Next Time", 30);
		exit(0);
	}
	data->map[data->p1][data->p2] = 'P';
	data->movescounter++;
	if (data->p == 1)
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->player1, data->p2 * 60 + 15, data->p1 * 40);
	else if (data->p == 0)
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->player2, data->p2 * 60 + 15, data->p1 * 40);
}
