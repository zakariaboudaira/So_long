/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:00:05 by zboudair          #+#    #+#             */
/*   Updated: 2022/02/07 09:25:58 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*set_window(t_data	*data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			put_window(data, i, j);
			if (data->map[i][j] == 'Y')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->enemy1, j * 60 + 15 - 10, i * 40);
			}
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->bar,
		(data->column / 2) * 60, 0 * 40 + 8);
	return (0);
}

void	put_window(t_data	*data, int i, int j)
{
	if (data->map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->img, j * 60, i * 40);
	else if (data->map[i][j] != '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->empty, j * 60, i * 40);
	if (data->map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->coin1, j * 60 + 15, i * 40 + 5);
	if (data->map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->door, j * 60 + 10, i * 40);
	if (data->map[i][j] == 'P')
	{
		data->p1 = i;
		data->p2 = j;
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->player1, j * 60 + 15, i * 40);
		data->p = 1;
	}
}
