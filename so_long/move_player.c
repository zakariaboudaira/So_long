/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:25:22 by zboudair          #+#    #+#             */
/*   Updated: 2022/02/07 10:23:06 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	move_player(t_data	*data, int s)
{
	if (s == 'r')
		move_right(data);
	if (s == 'l' )
		move_left(data);
	if (s == 'u')
		move_up(data);
	if (s == 'd')
		move_down(data);
	put_bar(data);
	return (0);
}

void	put_bar(t_data	*data)
{
	char	*ret;

	ret = ft_itoa(data->movescounter);
	if (data->movescounter < 100)
	{
		put1(data, (data->column / 2) * 60, 0 * 40 + 8);
		put2(data, (data->column / 2) * 60 + 23, 0 * 40 + 10, ret);
	}
	else if (data->movescounter < 1000)
	{
		put1(data, (data->column / 2) * 60, 0 * 40 + 8);
		put2(data, (data->column / 2) * 60 + 15, 0 * 40 + 10, ret);
	}
	else
	{
		put1(data, (data->column / 2) * 60, 0 * 40 + 8);
		put2(data, (data->column / 2) * 60 + 5, 0 * 40 + 10, ret);
	}
	free(ret);
}

void	put1(t_data	*data, int j, int i)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->bar, j, i);
}

void	put2(t_data	*data, int j, int i, char *ret)
{
	mlx_string_put(data->mlx, data->mlx_win, j, i, 0xFFFFFFFF, ret);
}
