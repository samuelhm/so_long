/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:58:56 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/19 15:54:35 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	move_to(t_game *game, int key);
static void	move(t_game *game, int x, int y, int p_x);
static int	can_move(char box);
static void	do_move(t_game *game, int x, int y);

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
		move(game, 0, -1, game->player_x);
	else if (key == KEY_RIGHT)
		move(game, 0, 1, game->player_x);
	else if (key == KEY_UP)
		move(game, -1, 0, game->player_x);
	else if (key == KEY_DOWN)
		move(game, 1, 0, game->player_x);
}

static void	move(t_game *game, int x, int y, int p_x)
{
	int	p_y;

	p_y = game->player_y;
	get_position(game);
	if (!game->map[p_x + x][p_y + y])
		return ;
	if (can_move(game->map[p_x + x][p_y + y]))
	{
		if (game->map[p_x + x][p_y + y] == 'E')
		{
			if (game->items == 0)
			{
				add_print_score(game);
				close_window_message(game, "\nYou exit!! congrats\n");
			}
		}
		else
		{
			add_print_score(game);
			if (game->map[p_x + x][p_y + y] == 'C')
				game->items--;
			do_move(game, x, y);
		}
	}
}

static void	do_move(t_game *game, int x, int y)
{
	int	p_x;
	int p_y;

	p_x = game->player_x;
	p_y = game->player_y;
	game->map[p_x][p_y] = '0';
	game->map[p_x + x][p_y + y] = 'P';
	game->player_x += x;
	game->player_y += y;
	paint(game);
}
static int	can_move(char box)
{
	return (box == '0' || box == 'C' || box == 'E');
}
