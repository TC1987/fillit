/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 09:35:43 by tcho              #+#    #+#             */
/*   Updated: 2018/12/16 05:24:26 by tcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "fillit.h"
#include "libft.h"

int	main(int argc, char *argv[])
{
	int			fd;
	t_pieces	*list;

	list = init_list();
	if (((fd = open(argv[1], O_RDONLY)) == -1) || (argc != 2))
	{
		ft_putstr("usage: ./fillit file\n");
		return (0);
	}
	if (!validate_file(fd, list) || !validate_size(list))
	{
		ft_putstr("error\n");
		return (0);
	}
	reset(list);
	set_size_letter(list);
	solve(list);
	close(fd);
	free_all(&list);
}
