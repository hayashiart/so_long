/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 03:48:27 by slin              #+#    #+#             */
/*   Updated: 2022/08/24 03:48:29 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_cond(char *string_map, t_counter *counter, t_game *game, int *i)
{
	if ((string_map[*i] == '\n') && ((string_map[*i + 1] == '\0')
			|| (string_map[*i + 1] == '\n')))
	{
		ft_printf("Error, invalid file\n");
		free(game->plot.temp);
		exit(1);
	}
	if (string_map[*i] == 'C')
		counter->collectible++;
	else if (string_map[*i] == 'E')
		counter->exit++;
	else if (string_map[*i] == 'P')
		counter->start++;
	else if (string_map[*i] == '0')
		counter->empty++;
	*i = *i + 1;
}

static t_counter	start_counter(char *string_map, t_game *game, int i)
{
	t_counter	counter;

	counter.collectible = 0;
	counter.start = 0;
	counter.exit = 0;
	counter.movements = 0;
	counter.empty = 0;
	while (string_map[i] != '\0')
		ft_cond(string_map, &counter, game, &i);
	if (!(counter.collectible > 0 && counter.exit == 1
			&& counter.start == 1 && counter.empty > 0))
	{
		ft_printf(RED"Error the content of the file is invalid\n"ENDC);
		free(game->plot.temp);
		exit(1);
	}
	return (counter);
}

static	char	*gnl_strjoinfree(char *s1, char *s2)
{
	char	*nstring;
	size_t	i;
	size_t	a;

	nstring = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	a = 0;
	if (nstring == 0)
		return (0);
	while (s1[i] != '\0')
	{
		nstring[i] = s1[i];
		i++;
	}
	while (s2[a] != '\0')
	{
		nstring[i + a] = s2[a];
		a++;
	}
	nstring[i + a] = '\0';
	free(s1);
	s1 = NULL;
	return (nstring);
}

int	len_map(char **map, t_game *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = ft_strlen(map[0]);
	while (map[i] != 0)
	{
		j = ft_strlen(map[i]);
		if (k != j)
		{
			free_map(game);
			ft_printf(RED"Invalid file because of the shape of the map\n"ENDC);
			exit(1);
		}
		i++;
	}
	return (k);
}

void	init_map(t_game *game, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf(RED"Can't find file"ENDC);
		exit(1);
	}
	game->plot.temp = ft_strdup("");
	game->plot.height = 0;
	while (fd)
	{
		game->plot.line = get_next_line(fd);
		if (game->plot.line == NULL)
			break ;
		game->plot.temp = gnl_strjoinfree(game->plot.temp, game->plot.line);
		free(game->plot.line);
		game->plot.height++;
	}
	game->counter = start_counter(game->plot.temp, game, 0);
	game->plot.map = ft_split(game->plot.temp, '\n');
	free(game->plot.temp);
	game->plot.length = len_map(game->plot.map, game);
	close(fd);
	return ;
}
