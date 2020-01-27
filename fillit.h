/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 09:39:12 by tcho              #+#    #+#             */
/*   Updated: 2018/12/09 00:03:02 by tcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define MAX_PIECES 26
# define MAX_HEIGHT 4
# define MAX_WIDTH 4

typedef struct		s_piece {
	char			letter;
	int				hash_count;
	int				dot_count;
	int				*x;
	int				*y;
	int				width;
	int				height;
	struct s_piece	*next;
}					t_piece;

typedef struct		s_pieces {
	int				size;
	struct s_piece	*head;
	struct s_piece	*tail;
}					t_pieces;

int					valid_char(char *buffer, int i, t_piece *node);
int					verify_newline(int fd);
int					verify_hash(int x, int y, char **map);
int					validate_file(int fd, t_pieces *list);
int					check_count(int hash_count, int dots_count);
int					validate_piece(t_piece *node);
int					validate_size(t_pieces *list);
void				free_map(char ***map, int size);
t_pieces			*init_list(void);
t_piece				*init_node(void);
void				add_node(t_pieces **list, t_piece *node);
void				remove_node(t_pieces **list, int index);
void				free_node(t_piece **current);
void				free_all(struct s_pieces **list);
int					get_init_size(int piece_count);
int					check_fit(char **map, t_piece *current, int i, int j);
void				remove_piece(char **map, t_piece *current, int i, int j);
int					fill_board(char **map, t_piece *current, int size);
void				set_size_letter(t_pieces *list);
int					solve(t_pieces *list);
void				init_array(int *arr, size_t size);
int					*ft_intnew(size_t size);
char				**initialize_map(char c, int size);
int					push(int *arr, int num);
int					find_max(int *nums);
int					find_min(int *nums);
int					display_map(char **map, int size);
void				reset(t_pieces *list);
void				init_array(int *arr, size_t size);
int					check_if_space(t_piece *current, int size, int i, int j);

#endif
