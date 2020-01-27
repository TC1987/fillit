/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 22:59:57 by tcho              #+#    #+#             */
/*   Updated: 2018/12/08 23:37:03 by tcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "fillit.h"
#include "libft.h"

int		*ft_intnew(size_t size)
{
	int *container;

	if (!(container = (int *)malloc(sizeof(int) * size)))
		return (NULL);
	init_array(container, size);
	return (container);
}

void	init_array(int *arr, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		arr[i] = -1;
		i++;
	}
}

char	**initialize_map(char c, int size)
{
	int		i;
	char	*row;
	char	**map;

	i = 0;
	map = (char **)malloc(sizeof(char *) * size);
	while (i < size)
	{
		row = (char *)malloc(sizeof(char) * size);
		if (!(map[i] = ft_memset(row, c, size)))
			return (NULL);
		i++;
	}
	return (map);
}
