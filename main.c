/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 23:01:09 by slin              #+#    #+#             */
/*   Updated: 2022/08/19 23:01:10 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strend_cmp(char *name, char *end)
{
	int	name_len;
	int	ext_len;

	name_len = ft_strlen(name);
	ext_len = ft_strlen(end);
	if (name_len <= ext_len)
		return (0);
	name += name_len - ext_len;
	while (*name)
	{
		if (*name != *end)
			return (0);
		name++;
		end++;
	}
	return (1);
}

int	valid_file(int argc, char *file)
{
	if (argc == 1)
	{
		ft_printf(RED"Error no arguments\n"ENDC);
		exit(1);
	}
	if (argc > 2)
	{
		ft_printf(RED"Only the first file will be used\n"ENDC);
		return (0);
	}
	if (!(ft_strend_cmp(file, ".ber")))
	{
		ft_printf(RED"Error map should be a .ber file\n"ENDC);
		exit(1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	valid_file(argc, argv[1]);
	init_map(&game, argv[1]);
	init_so_long(&game);
	init_images(&game);
	mlx_hook(game.window_pointer, 3, (1L << 1), key_check, &game);
	mlx_hook(game.window_pointer, 17, (0L), red_cross, &game);
	mlx_hook(game.window_pointer, 12, (0L), ft_maker, &game);
	mlx_loop(game.mlx_pointer);
	return (0);
}
