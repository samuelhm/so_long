/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x11_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 10:12:29 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/19 00:22:42 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	close_window_message(t_game *game, const char *error)
{
	unload_images(game);
	if (!game->map)
		ft_free_2d_array((void **)game->map);
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
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
	unload_images(game);
	if (!game->map)
		ft_free_2d_array((void **)game->map);
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
	}
	if (game)
		free(game);
	exit(0);
	return (0);
}
