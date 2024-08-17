/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 21:03:21 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/17 21:58:12 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	init(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (0);
	game->images = set_up_images(game->mlx, GAME_W, GAME_H);
	if (game->images == NULL)
		return (0);
	game->mlx_win = mlx_new_window(game->mlx, 1024, 768, "SO_LONG");
	if (game->mlx_win == NULL)
		return (0);
	return (1);
}
