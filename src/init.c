/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 21:03:21 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/19 13:11:53 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static char	*buildpath(const char *mapname);
static int	init_map(t_game *game, const char *mapname);

int	init(t_game *game, char *mapname)
{
	if (!init_map(game, mapname))
		return (0);
	game->win_w = ft_strlen(game->map[0]) * GAME_W;
	game->win_h = 0;
	while (game->map[game->win_h])
		game->win_h++;
	game->win_h *= GAME_H;
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->images = set_up_images(game->mlx, GAME_W, GAME_H);
	if (!game->images)
		return (0);
	game->mlx_win = mlx_new_window(game->mlx, game->win_w, game->win_h, "SO_LONG");
	if (!game->mlx_win)
		return (0);
	return (1);
}

static int	init_map(t_game *game, const char *mapname)
{
	char	*path;
	int		map_file;

	path = buildpath(mapname);
	if (!path)
		close_window_message(game, ERR_PATH);
	map_file = open(path, 0);
	if (map_file == -1)
	{
		free(path);
		close_window_message(game, ERR_FILE);
	}
	close(map_file);
	game->map = map_is_ok(path);
	if (!game->map)
	{
		free(path);
		return (0);
	}
	free(path);
	return (1);
}

static char	*buildpath(const char *mapname)
{
	char	*path;
	char	*temp;

	if (!mapname)
		return (NULL);
	path = ft_strdup("./maps/");
	if (!path)
		return (NULL);
	temp = ft_strjoin(path, mapname);
	free(path);
	if (!temp)
		return (NULL);
	path = temp;
	temp = ft_strjoin(path, ".ber");
	free (path);
	if (!temp)
		return (NULL);
	path = ft_strdup(temp);
	free(temp);
	if (!path)
		return (NULL);
	return (path);
}
