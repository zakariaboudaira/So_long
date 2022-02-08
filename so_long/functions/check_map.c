/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:26:28 by zboudair          #+#    #+#             */
/*   Updated: 2022/02/08 16:55:15 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	check_map(t_data	*data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
			j++;
		if (j != data->column)
			return (0);
		i++;
	}
	if (wall_checker(data) == 0)
		return (0);
	if (wall_checker2(data) == 0)
		return (0);
	if (checker(data) == 0)
		return (0);
	return (1);
}

char	wall_checker(t_data	*data)
{
	int	i;
	int	line;

	line = data->line - 1;
	i = 0;
	while (data->map[0][i])
	{
		if (data->map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (data->map[line][i])
	{
		if (data->map[line][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

char	wall_checker2(t_data	*data)
{
	int	start;
	int	end;

	end = data->column - 1;
	start = 1;
	while (start < data->line - 1)
	{
		if (data->map[start][0] != '1' || data->map[start][end] != '1')
			return (0);
		start++;
	}
	return (1);
}

char	checker(t_data	*data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] != '1' && data->map[i][j] != '0'
					&& data->map[i][j] != 'C'
					&& data->map[i][j] != 'P'
					&& data->map[i][j] != 'E'
					&& data->map[i][j] != 'Y')
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
