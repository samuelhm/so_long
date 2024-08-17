/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 22:09:45 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/17 21:26:58 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"



int	main(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (game == NULL)
		return (1);
	if (!init(game))
		close_window(game);
	paint(game->mlx, game->mlx_win, game->images);
	mlx_hook(game->mlx_win, 17, 0, close_window, game);
	mlx_hook(game->mlx_win, 2, 1L << 0, handle_key, game);
	mlx_loop(game->mlx);
	return (0);
}
