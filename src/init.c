/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 21:03:21 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/22 11:56:49 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	init_map(t_game *game, const char *mapname);

int	init(t_game *game, char *mapname)
{
	void	*win;

	if (!init_map(game, mapname))
		close_window_message(game, ERR_MAP2);
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
	win = mlx_new_window(game->mlx, game->win_w, game->win_h, "SO_LONG");
	game->mlx_win = win;
	if (!game->mlx_win)
		return (0);
	return (1);
}

static int	init_map(t_game *game, const char *path)
{
	int		map_file;

	if (!path)
		close_window_message(game, ERR_PATH);
	map_file = open(path, 0);
	if (map_file == -1)
		close_window_message(game, ERR_FILE);
	close(map_file);
	game->map = map_is_ok(path, &game->items);
	if (!game->map)
		return (0);
	return (1);
}
