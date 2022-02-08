/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboudair <zboudair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:43:39 by zboudair          #+#    #+#             */
/*   Updated: 2022/02/08 16:55:48 by zboudair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		size;
	int		i;
	int		j;
	char	*arr;

	i = 0;
	j = 0;
	if (s2 == NULL)
		return (0);
	size = ft_strlen(s1) + ft_strlen(s2);
	arr = malloc((size + 1) * sizeof(char));
	if (arr == 0)
		return (0);
	if (s1)
	{
		while (s1[j] && i < size)
			arr[i++] = s1[j++];
	}
	j = 0;
	while (s2[j] && i < size)
		arr[i++] = s2[j++];
	arr[i] = '\0';
	free(s1);
	return (arr);
}
