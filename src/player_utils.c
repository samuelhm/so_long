/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 01:57:50 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/28 22:15:00 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = i;
				game->player_y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	add_print_score(t_game *game)
{
	game->moves++;
	ft_printf(CLR_LN);
	ft_printf("Moves: %d", game->moves);
}

void	init_map_checks(int *c)
{
	c[0] = 0;
	c[1] = 0;
	c[2] = 0;
}
