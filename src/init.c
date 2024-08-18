/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 21:03:21 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/18 23:52:11 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static char	*buildpath(const char *mapname);
static int	init_map(t_game *game, const char *mapname);

int	init(t_game *game, char *mapname)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->images = set_up_images(game->mlx, GAME_W, GAME_H);
	if (!game->images)
		return (0);
	game->mlx_win = mlx_new_window(game->mlx, 1024, 768, "SO_LONG");
	if (!game->mlx_win)
		return (0);
	if (!init_map(game, mapname))
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
	if (!map_is_ok(path))
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
