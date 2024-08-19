/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 22:09:45 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/19 22:43:11 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	init_tgame(t_game *game);

int	main(int argc, char *argv[])
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	init_tgame(game);
	if (argc != 2)
		close_window_message(game, ERR_MAP);
	if (game == NULL)
		return (1);
	if (!init(game, argv[1]))
	{
		ft_printf("Cerrando init 0\n");
		close_window_message(game, ERR_INIT);
	}
	mlx_hook(game->mlx_win, 17, 0, close_window, game);
	mlx_hook(game->mlx_win, 2, 1L << 0, handle_key, game);
	paint(game);
	mlx_loop(game->mlx);
	return (0);
}

static void	init_tgame(t_game *game)
{
	game->images = NULL;
	game->map = NULL;
	game->mlx = NULL;
	game->mlx_win = NULL;
	game->map = NULL;
	game->player_x = 0;
	game->player_y = 0;
	game->win_h = 0;
	game->win_w = 0;
	game->moves = 0;
	game->items = 0;
}
