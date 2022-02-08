/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:58:18 by zboudair          #+#    #+#             */
/*   Updated: 2022/02/08 16:55:24 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	counter(t_data	*data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				data->coinscounter++;
			if (data->map[i][j] == 'P')
				data->pcount++;
			if (data->map[i][j] == 'E')
				data->ecount++;
			if (data->map[i][j] == 'Y')
				data->n_en++;
			j++;
		}
		i++;
	}
	dir(data);
}

void	dir(t_data	*data)
{
	int	i;

	i = -1;
	data->dir = (int *)malloc(sizeof(int) * data->n_en);
	while (++i < data->n_en)
		data->dir[i] = 1;
}
