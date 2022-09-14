/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 01:18:48 by slin              #+#    #+#             */
/*   Updated: 2022/08/20 01:18:50 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_plotmap(t_game *game, int y, int x)
{
	if (game->plot.map[y][x] == 'E')
	{
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->portal.ptr, (32 * x), (32 * y));
	}
	else if (game->plot.map[y][x] == '1')
	{
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->wall.ptr, (32 * x), (32 * y));
	}
	else if (game->plot.map[y][x] == 'C')
	{
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->collect.ptr, (32 * x), (32 * y));
	}
	else
	{
		mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
			game->floor.ptr, (32 * x), (32 * y));
	}
}

static void	check_element_map(t_game *game, int y, int x)
{
	if ((game->plot.map[game->plot.height - 1][x] != '1') ||
			(game->plot.map[0][x] != '1') ||
			(game->plot.map[y][game->plot.length - 1] != '1') ||
			(game->plot.map[y][0] != '1'))
	{
		ft_printf(RED"Error not surrounded by trees\n"ENDC);
		destroyfree_all(game);
		exit(1);
	}
	if (game->plot.height == game->plot.length)
	{
		ft_printf(RED"Error map not rectangular\n"ENDC);
		destroyfree_all(game);
		exit(1);
	}
	if (!(ft_strchr("01CEP", game->plot.map[y][x])))
	{
		ft_printf(RED"Error invalid character in the map\n"ENDC);
		destroyfree_all(game);
		exit (1);
	}
	ft_plotmap(game, y, x);
	return ;
}

void	map_maker(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->plot.map[y])
	{
		x = 0;
		while (game->plot.map[y][x])
		{
			check_element_map(game, y, x);
			x++;
		}
		y++;
	}
	return ;
}
