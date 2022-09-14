/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 03:34:12 by slin              #+#    #+#             */
/*   Updated: 2022/08/01 03:34:13 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include "./libft/libft.h"
# include "./gnl/get_next_line.h"
# include "./ft_printf/ft_printf.h"
# include "minilibx/mlx.h"

# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100
# define ESC 65307
# define RED "\033[1m\033[31m"
# define GREEN "\033[1m\033[32m"
# define ENDC "\033[0m"

typedef struct s_counter
{
	int	empty;
	int	collectible;
	int	exit;
	int	start;
	int	movements;
}	t_counter;

typedef struct s_img
{
	void	*ptr;
	int		*pixels;
	int		line_size;
	int		mem;
	int		x;
	int		y;
	int		movements;
}	t_img;

typedef struct s_draw
{
	char	**map;
	int		height;
	int		length;
	char	*line;
	char	*temp;
}	t_draw;

typedef struct s_game
{
	void		*mlx_pointer;
	void		*window_pointer;
	t_counter	counter;
	t_draw		plot;
	t_img		character_d;
	t_img		character_l;
	t_img		character_r;
	t_img		character_u;
	t_img		floor;
	t_img		wall;
	t_img		collect;
	t_img		portal;
}	t_game;

int		len_map(char **map, t_game *game);
int		ft_maker(t_game *game);
void	map_maker(t_game *game);
void	init_map(t_game *game, char *path);
void	init_so_long(t_game *game);
void	init_images(t_game *game);
void	destroyfree_all(t_game *game);
void	free_map(t_game *game);
int		red_cross(t_game *game);
int		mini_maker(t_game *game);
void	player_init(t_game *game);
int		key_check(int keycode, t_game *game);
void	print_moves(t_game *game);
void	move_down(t_game *game);
void	move_up(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);

#endif
