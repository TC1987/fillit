/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 22:46:32 by tcho              #+#    #+#             */
/*   Updated: 2018/12/08 23:12:12 by tcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

void	free_map(char ***map, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free((*map)[i]);
		i++;
	}
	free(*map);
}

void	free_node(t_piece **current)
{
	free((*current)->x);
	free((*current)->y);
	free(*current);
}

void	free_all(t_pieces **list)
{
	t_piece *current;
	t_piece *temp;

	if (!list || !(*list))
		return ;
	current = (*list)->head;
	while (current)
	{
		temp = current;
		current = current->next;
		free_node(&temp);
	}
	free(*list);
}
