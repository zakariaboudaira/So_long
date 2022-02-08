/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:50:11 by zboudair          #+#    #+#             */
/*   Updated: 2022/02/08 08:16:09 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long(t_data	*data)
{
	data->mlx = mlx_init();
	gui(data);
	mlx_loop_hook(data->mlx, anime, data);
	mlx_hook(data->mlx_win, 17, 1, &ft_close, data);
	mlx_hook(data->mlx_win, 2, 0, key_hook, data);
	mlx_loop(data->mlx);
}

void	gui(t_data *data)
{
	data->mlx_win = mlx_new_window(data->mlx,
			data->column * 60, data->line * 40, "so_long");
	data->img = mlx_xpm_file_to_image(data->mlx,
			"img/Wall.xpm", &data->w, &data->h);
	data->empty = mlx_xpm_file_to_image(data->mlx,
			"img/space.xpm", &data->w, &data->h);
	data->coin1 = mlx_xpm_file_to_image(data->mlx,
			"coins/coin1.xpm", &data->w, &data->h);
	data->coin2 = mlx_xpm_file_to_image(data->mlx,
			"coins/coin2.xpm", &data->w, &data->h);
	ui(data);
	set_window(data);
}

int	anime(t_data	*data)
{
	data->i++;
	if (data->i > 7000)
		data->i = 0;
	if (data->i == 1000)
		set_coins(data, data->coin1);
	if (data->i == 2000)
		set_coins(data, data->coin2);
	if (data->i == 3000)
		set_coins(data, data->coin3);
	if (data->i == 4000)
		set_coins(data, data->coin4);
	if (data->i == 5000)
		set_coins(data, data->coin5);
	if (data->i == 6000)
		set_coins(data, data->coin6);
	if (data->i == 7000)
		move_enemy(data);
	return (0);
}

int	key_hook(int keycode, t_data	*data)
{
	if (keycode == 126 || keycode == 13)
		move_player(data, 'u');
	if (keycode == 125 || keycode == 1)
		move_player(data, 'd');
	if (keycode == 123 || keycode == 0)
		move_player(data, 'l');
	if (keycode == 124 || keycode == 2)
		move_player(data, 'r');
	if (keycode == 53)
		exit(0);
	return (0);
}

void	ui(t_data	*data)
{
	data->coin3 = mlx_xpm_file_to_image(data->mlx,
			"coins/coin3.xpm", &data->w, &data->h);
	data->coin4 = mlx_xpm_file_to_image(data->mlx,
			"coins/coin4.xpm", &data->w, &data->h);
	data->coin5 = mlx_xpm_file_to_image(data->mlx,
			"coins/coin5.xpm", &data->w, &data->h);
	data->coin6 = mlx_xpm_file_to_image(data->mlx,
			"coins/coin6.xpm", &data->w, &data->h);
	data->door = mlx_xpm_file_to_image(data->mlx,
			"img/door.xpm", &data->w, &data->h);
	data->player1 = mlx_xpm_file_to_image(data->mlx,
			"img/player1.xpm", &data->w, &data->h);
	data->player2 = mlx_xpm_file_to_image(data->mlx,
			"img/player2.xpm", &data->w, &data->h);
	data->enemy1 = mlx_xpm_file_to_image(data->mlx,
			"img/ene1.xpm", &data->w, &data->h);
	data->enemy2 = mlx_xpm_file_to_image(data->mlx,
			"img/ene2.xpm", &data->w, &data->h);
	data->bar = mlx_xpm_file_to_image(data->mlx,
			"img/bar.xpm", &data->w, &data->h);
}
