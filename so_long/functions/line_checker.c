/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:39:50 by zboudair          #+#    #+#             */
/*   Updated: 2022/02/08 16:56:00 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	newline_checker(t_data	*data)
{
	int	i;

	i = 0;
	if (data->saved[0] != '1')
		return (0);
	while (data->saved[i] != '\0')
	{
		if (data->saved[i] == '\n' && data->saved[i + 1] == '\n')
			return (0);
		if (data->saved[i] == '\n' && data->saved[i + 1] == '\0')
			return (0);
		i++;
	}
	return (1);
}
