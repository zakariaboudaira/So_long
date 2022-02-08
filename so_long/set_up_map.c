/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:10:52 by zboudair          #+#    #+#             */
/*   Updated: 2022/02/08 08:14:06 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	set_up_map(char	*path, t_data	*data)
{
	if (!set_map(path, data))
		return (0);
	set_line(data->saved, data);
	set_column(data->saved, data);
	return (1);
}

void	set_line(char	*str, t_data	*data)
{
	int	i;

	i = 0;
	data->line++;
	while (str[i])
	{
		if (str[i] == '\n')
			data->line++;
		i++;
	}
}

void	set_column(char	*str, t_data	*data)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
	{
		data->column++;
		i++;
	}
}

int	set_map(char	*path, t_data	*data)
{
	char	s[2];
	int		size;
	int		fd;

	data->saved = NULL;
	fd = open(path, O_RDONLY);
	size = 1;
	if (fd < 0)
		return (0);
	while (size)
	{
		size = read(fd, s, 1);
		if (size == -1)
			return (0);
		s[size] = '\0';
		data->saved = ft_strjoin(data->saved, s);
	}
	close(fd);
	data->map = ft_split(data->saved, '\n');
	return (1);
}
