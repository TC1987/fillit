/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 02:01:50 by tcho              #+#    #+#             */
/*   Updated: 2018/12/08 23:32:14 by tcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "fillit.h"
#include "libft.h"

t_pieces	*init_list(void)
{
	t_pieces *list;

	if (!(list = (t_pieces *)malloc(sizeof(t_pieces))))
		return (NULL);
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	return (list);
}

t_piece		*init_node(void)
{
	t_piece *node;

	if (!(node = (t_piece *)malloc(sizeof(t_piece))))
		return (NULL);
	node->letter = 0;
	node->hash_count = 0;
	node->dot_count = 0;
	node->width = 0;
	node->height = 0;
	node->x = ft_intnew(4);
	node->y = ft_intnew(4);
	node->next = NULL;
	return (node);
}

void		add_node(t_pieces **list, t_piece *node)
{
	if (!(*list)->head)
	{
		(*list)->head = node;
		(*list)->tail = node;
	}
	else
	{
		(*list)->tail->next = node;
		(*list)->tail = node;
	}
	(*list)->size++;
}

void		remove_node(t_pieces **list, int index)
{
	int		i;
	t_piece	*parent;
	t_piece	*current;

	if (!(*list)->head)
		return ;
	parent = NULL;
	current = (*list)->head;
	i = 0;
	while (current && i < index)
	{
		parent = current;
		current = current->next;
		i++;
	}
	if (i == 0)
		(*list)->head = current->next;
	else
		parent->next = current->next;
	free_node(&current);
}
