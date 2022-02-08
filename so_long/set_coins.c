/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_coins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:37:11 by zboudair          #+#    #+#             */
/*   Updated: 2022/02/06 19:00:22 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_coins(t_data	*data, void	*img)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->line)
	{
		j = -1;
		while (++j < data->column)
		{
			if (data->map[i][j] == 'C')
			{
				mlx_put_image_to_window(data->mlx,
					data->mlx_win, data->empty, j * 60, i * 40);
				mlx_put_image_to_window(data->mlx,
					data->mlx_win, img, j * 60 + 15, i * 40 + 5);
			}
		}
	}
}
