/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 22:09:45 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/19 01:18:22 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char *argv[])
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (argc != 2)
	{
		close_window_message(game,ERR_MAP);
	}
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
