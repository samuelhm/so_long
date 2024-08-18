/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paintwindows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:23:29 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/19 01:19:42 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	paint(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->win_W)
	{
		j = 0;
		while (j < game->win_H)
		{
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->images->wall1, i, j);
			j += 32;
		}
		i += 32;
	}
}
