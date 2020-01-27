/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 00:07:40 by tcho              #+#    #+#             */
/*   Updated: 2018/12/08 23:47:41 by tcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "fillit.h"
#include "libft.h"

int		push(int *arr, int num)
{
	int	i;

	i = 0;
	while ((arr[i] != -1) && i < 4)
		i++;
	if (i < 4)
	{
		arr[i] = num;
		return (1);
	}
	return (0);
}

void	set_size_letter(t_pieces *list)
{
	int		letter;
	t_piece	*current;

	letter = 'A';
	current = list->head;
	while (current)
	{
		current->letter = letter++;
		current->width = find_max(current->x) - find_min(current->x) + 1;
		current->height = find_max(current->y) - find_min(current->y) + 1;
		current = current->next;
	}
}

int		display_map(char **map, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putchar(map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	return (1);
}

void	reset(t_pieces *list)
{
	int		i;
	int		y_difference;
	int		x_difference;
	t_piece	*current;

	current = list->head;
	while (current)
	{
		i = 0;
		y_difference = find_min(current->y) - 0;
		x_difference = find_min(current->x) - 0;
		while (i < 4)
		{
			current->y[i] -= y_difference;
			current->x[i] -= x_difference;
			i++;
		}
		current = current->next;
	}
}

int		verify_newline(int fd)
{
	char buffer[2];

	if (read(fd, buffer, 1))
	{
		buffer[1] = '\0';
		if (buffer[0] != '\n')
			return (0);
	}
	return (1);
}
