/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:58:56 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/17 17:12:14 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	handle_key(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_window(game);
	if (keycode == KEY_DOWN)
		close_window(game);
	if (keycode == KEY_UP)
		close_window(game);
	if (keycode == KEY_LEFT)
		close_window(game);
	if (keycode == KEY_RIGHT)
		close_window(game);
	return (0);
}
