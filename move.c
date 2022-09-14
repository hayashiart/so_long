/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 19:28:43 by slin              #+#    #+#             */
/*   Updated: 2022/08/22 19:28:45 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_down(t_game *game)
{
	if (!(game->plot.map[((game->character_d.y + 32) / 32)]
			[(game->character_d.x / 32)] == '1'))
	{
		game->character_d.y += 32;
		map_maker(game);
		print_moves(game);
	}
	mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
		game->character_d.ptr, game->character_d.x, game->character_d.y);
	return ;
}

void	move_up(t_game *game)
{
	if (!(game->plot.map[((game->character_d.y - 32) / 32)]
			[(game->character_d.x / 32)] == '1'))
	{
		game->character_d.y -= 32;
		map_maker(game);
		print_moves(game);
	}
	mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
		game->character_u.ptr, game->character_d.x, game->character_d.y);
	return ;
}

void	move_left(t_game *game)
{
	if (!(game->plot.map[(game->character_d.y / 32)]
			[((game->character_d.x - 32) / 32)] == '1'))
	{
		game->character_d.x -= 32;
		map_maker(game);
		print_moves(game);
	}
	mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
		game->character_l.ptr, game->character_d.x, game->character_d.y);
	return ;
}

void	move_right(t_game *game)
{
	if (!(game->plot.map[(game->character_d.y / 32)]
			[((game->character_d.x + 32) / 32)] == '1'))
	{
		game->character_d.x += 32;
		map_maker(game);
		print_moves(game);
	}
	mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
		game->character_r.ptr, game->character_d.x, game->character_d.y);
	return ;
}
