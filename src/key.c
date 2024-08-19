/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:58:56 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/19 15:00:29 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	move_to(t_game *game, int key);
static void	move(t_game *game, int x, int y);
static int	can_move(char box);

int	handle_key(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_window(game);
	if (keycode == KEY_DOWN)
		move_to(game, KEY_DOWN);
	if (keycode == KEY_UP)
		move_to(game, KEY_UP);
	if (keycode == KEY_LEFT)
		move_to(game, KEY_LEFT);
	if (keycode == KEY_RIGHT)
		move_to(game, KEY_RIGHT);
	return (0);
}

static void	move_to(t_game *game, int key)
{
	if (key == KEY_LEFT)
		move(game, 0, -1);
	else if (key == KEY_RIGHT)
		move(game, 0, 1);
	else if (key == KEY_UP)
		move(game, -1, 0);
	else if (key == KEY_DOWN)
		move(game, 1, 0);
}

static void	move(t_game *game, int x, int y)
{
	int	p_x;
	int	p_y;

	get_position(game);
	p_x = game->player_x;
	p_y = game->player_y;
	if (!game->map[p_x + x][p_y + y])
		return ;
	if (can_move(game->map[p_x + x][p_y + y]))
	{
		add_score(game);
		print_score(game);
		if (game->map[p_x + x][p_y + y] == 'E')
			close_window_message(game, "\nYou exit!! congrats\n");
		game->map[p_x][p_y] = '0';
		game->map[p_x + x][p_y + y] = 'P';
		game->player_x += x;
		game->player_y += y;
		paint(game);
	}
}

static int	can_move(char box)
{
	return (box == '0' || box == 'C' || box == 'E');
}
