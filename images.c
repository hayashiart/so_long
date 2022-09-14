/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:59:55 by slin              #+#    #+#             */
/*   Updated: 2022/08/20 16:59:57 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_so_long(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->mlx_pointer = mlx_init();
	mlx_get_screen_size(game->mlx_pointer, &i, &j);
	if (((game->plot.length * 32) > i) || ((game->plot.height * 32) > j))
	{
		free_map(game);
		mlx_destroy_display(game->mlx_pointer);
		free(game->mlx_pointer);
		ft_printf(RED"map size larger than display resolution\n"ENDC);
		exit(1);
	}
	else
	{
		game->window_pointer = mlx_new_window(game->mlx_pointer,
				(game->plot.length * 32), (game->plot.height * 32), "/so_long");
	}
}

void	init_images(t_game *game)
{
	game->wall.ptr = mlx_xpm_file_to_image(game->mlx_pointer,
			"./images/wall.xpm", &game->wall.x, &game->wall.y);
	game->floor.ptr = mlx_xpm_file_to_image(game->mlx_pointer,
			"./images/floor.xpm", &game->floor.x, &game->floor.y);
	game->collect.ptr = mlx_xpm_file_to_image(game->mlx_pointer,
			"./images/collectible.xpm", &game->collect.x, &game->collect.y);
	game->portal.ptr = mlx_xpm_file_to_image(game->mlx_pointer,
			"./images/portal.xpm", &game->portal.x, &game->portal.y);
	game->character_d.ptr = mlx_xpm_file_to_image(game->mlx_pointer,
			"./images/down.xpm", &game->character_d.x, &game->character_d.y);
	game->character_l.ptr = mlx_xpm_file_to_image(game->mlx_pointer,
			"./images/left.xpm", &game->character_l.x, &game->character_l.y);
	game->character_r.ptr = mlx_xpm_file_to_image(game->mlx_pointer,
			"./images/right.xpm", &game->character_r.x, &game->character_r.y);
	game->character_u.ptr = mlx_xpm_file_to_image(game->mlx_pointer,
			"./images/top.xpm", &game->character_u.x, &game->character_u.y);
}

void	destroyfree_all(t_game *game)
{
	mlx_destroy_image(game->mlx_pointer, game->wall.ptr);
	mlx_destroy_image(game->mlx_pointer, game->floor.ptr);
	mlx_destroy_image(game->mlx_pointer, game->collect.ptr);
	mlx_destroy_image(game->mlx_pointer, game->portal.ptr);
	mlx_destroy_image(game->mlx_pointer, game->character_d.ptr);
	mlx_destroy_image(game->mlx_pointer, game->character_l.ptr);
	mlx_destroy_image(game->mlx_pointer, game->character_r.ptr);
	mlx_destroy_image(game->mlx_pointer, game->character_u.ptr);
	mlx_destroy_window(game->mlx_pointer, game->window_pointer);
	mlx_destroy_display(game->mlx_pointer);
	free_map(game);
	free (game->mlx_pointer);
	return ;
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->plot.map[i])
	{
		free(game->plot.map[i]);
		game->plot.map[i] = NULL;
		i++;
	}
	free (game->plot.map);
	return ;
}
