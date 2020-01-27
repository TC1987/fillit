/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 03:40:49 by tcho              #+#    #+#             */
/*   Updated: 2018/12/08 23:31:57 by tcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"
#include "libft.h"

int		get_init_size(int piece_count)
{
	int i;
	int total_spots;

	i = 2;
	total_spots = piece_count * 4;
	while ((i * i) < total_spots)
		i++;
	return (i);
}

void	remove_piece(char **map, t_piece *current, int i, int j)
{
	int index;

	index = 0;
	while (index < 4)
	{
		if (map[i + current->y[index]][j + current->x[index]] ==
				current->letter)
			map[i + current->y[index]][j + current->x[index]] = '.';
		index++;
	}
}

int		fill_board(char **map, t_piece *current, int size)
{
	int	i;
	int	j;
	int result;

	i = -1;
	if (current == NULL)
		return (1);
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (check_if_space(current, size, i, j))
			{
				if ((result = check_fit(map, current, i, j)) == 0)
				{
					if (fill_board(map, current->next, size))
						return (1);
				}
				if (result == -1 || result == 0)
					remove_piece(map, current, i, j);
			}
		}
	}
	return (0);
}

int		solve(t_pieces *list)
{
	int		size;
	char	**map;

	size = get_init_size(list->size);
	while ((map = initialize_map('.', size)) &&
			!fill_board(map, list->head, size))
	{
		free_map(&map, size);
		size++;
	}
	display_map(map, size);
	free_map(&map, size);
	return (1);
}
