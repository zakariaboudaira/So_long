/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:07:24 by zboudair          #+#    #+#             */
/*   Updated: 2022/02/08 08:16:22 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char	**argc)
{
	t_data	data;
	char	*path;

	path = argc[1];
	if (ac != 2)
		return (0);
	check_extention(path);
	ini(&data);
	if (set_up_map(path, &data) == 0)
		ft_exit();
	if (newline_checker(&data) == 0)
		ft_exit();
	if (!check_map(&data))
		ft_exit();
	counter(&data);
	if (data.pcount != 1 || data.ecount <= 0
		|| data.coinscounter <= 0)
	{
		ft_exit();
	}
	so_long(&data);
	return (0);
}

void	ini(t_data	*data)
{
	data->n_en = 0;
	data->coinscounter = 0;
	data->pcount = 0;
	data->ecount = 0;
	data->movescounter = 0;
	data->line = 0;
	data->column = 0;
	data->i = 0;
}

void	check_extention(char *path)
{
	int	len_path;

	len_path = ft_strlen(path);
	if (len_path < 4)
		ft_exit();
	if (ft_strcmp(path + len_path - 4, ".ber"))
		ft_exit();
}
