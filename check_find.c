/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_find.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 22:58:38 by tcho              #+#    #+#             */
/*   Updated: 2018/12/08 23:37:26 by tcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "fillit.h"

int	check_if_space(t_piece *current, int size, int i, int j)
{
	if (((j + current->width) <= size) && ((i + current->height) <= size))
		return (1);
	return (0);
}

int	check_fit(char **map, t_piece *current, int i, int j)
{
	int index;

	index = 0;
	if (map[i + current->y[index]][j + current->x[index]] == '.')
	{
		while (index < 4)
		{
			if (map[i + current->y[index]][j + current->x[index]] != '.')
				return (-1);
			map[i + current->y[index]][j + current->x[index]] = current->letter;
			index++;
		}
		return (0);
	}
	return (1);
}

int	check_count(int hash_count, int dot_count)
{
	if (hash_count != 4 || dot_count != 12)
		return (0);
	return (1);
}

int	find_max(int *nums)
{
	int i;
	int max;

	i = 0;
	max = 0;
	while (i < 4)
	{
		if (nums[i] > max)
			max = nums[i];
		i++;
	}
	return (max);
}

int	find_min(int *nums)
{
	int	i;
	int	min;

	i = 0;
	min = 4;
	while (i < 4)
	{
		if (nums[i] < min)
			min = nums[i];
		i++;
	}
	return (min);
}
