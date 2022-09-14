/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:36:39 by slin              #+#    #+#             */
/*   Updated: 2022/08/22 18:36:41 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	red_cross(t_game *game)
{
	destroyfree_all(game);
	exit(0);
}

int	ft_maker(t_game *game)
{
	map_maker(game);
	if (game->counter.movements == 0)
		player_init(game);
	return (0);
}

void	player_init(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->plot.map[y])
	{
		x = 0;
		while (game->plot.map[y][x])
		{
			if (game->plot.map[y][x] == 'P')
			{
				game->character_d.x = (32 * x);
				game->character_d.y = (32 * y);
				mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
					game->character_d.ptr, (32 * x), (32 * y));
				return ;
			}
			x++;
		}
		y++;
	}
	return ;
}

int	key_check(int keycode, t_game *game)
{
	game->character_d.mem = 0;
	if (keycode == ESC)
	{
		destroyfree_all(game);
		exit(0);
	}
	if (keycode == LEFT)
		move_left(game);
	if (keycode == RIGHT)
		move_right(game);
	if (keycode == UP)
		move_up(game);
	if (keycode == DOWN)
		move_down(game);
	return (0);
}

void	print_moves(t_game *game)
{
	game->counter.movements += 1;
	if (game->plot.map[game->character_d.y / 32]
		[game->character_d.x / 32] == 'C')
	{
		game->plot.map[game->character_d.y / 32]
		[game->character_d.x / 32] = '0';
		game->counter.collectible--;
	}
	if (game->plot.map[game->character_d.y / 32]
		[game->character_d.x / 32] == 'E' && game->counter.collectible == 0)
	{
		ft_printf(GREEN"\n\n END\n"ENDC);
		destroyfree_all(game);
		exit(0);
	}
	ft_printf("\r Movements: %d\n", game->counter.movements);
	return ;
}
