/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 01:57:50 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/19 14:56:50 by shurtado         ###   ########.fr       */
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

void	print_score(t_game *game)
{
	ft_printf(CLR_LN);
	ft_printf("Moves: %d", game->moves);
}

void	add_score(t_game *game)
{
	game->moves++;
}
