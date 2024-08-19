/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paintwindows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:23:29 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/19 01:39:02 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	pblock(t_game *game, int x, int y, char image)
{
	void	*mlx;
	void	*win;

	mlx = game->mlx;
	win = game->mlx_win;
	if (image == '0')
		mlx_put_image_to_window(mlx, win, game->images->empty, x ,y);
	else if (image == '1')
		mlx_put_image_to_window(mlx, win, game->images->wall1, x ,y);
	else if (image == 'C')
		mlx_put_image_to_window(mlx, win, game->images->item, x ,y);
	else if (image == 'E')
		mlx_put_image_to_window(mlx, win, game->images->exit, x ,y);
	else if (image == 'P')
		mlx_put_image_to_window(mlx, win, game->images->hero, x ,y);
}

void	paint(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			pblock(game, j * GAME_W, i * GAME_H, game->map[i][j]);
			j++;
		}
		i++;
	}
}
