/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x11_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 10:12:29 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/19 22:14:19 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	close_window_message(t_game *game, const char *error)
{
	if (game->images)
		unload_images(game);
	if (game->map)
		free_map(game->map, (game->win_h / GAME_H));
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game)
		free(game);
	if (error)
		ft_printf("%s", error);
	exit(0);
	return (0);
}

int	close_window(t_game *game)
{
	if (game->images)
		unload_images(game);
	if (game->map)
		free_map(game->map, (game->win_h / GAME_H));
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game)
		free(game);
	exit(0);
	return (0);
}
