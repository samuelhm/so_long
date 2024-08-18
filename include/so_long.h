/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 22:09:53 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/18 20:15:52 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/mlx/mlx.h"
# include "../lib/libft/libft.h"
# include <math.h>
# include <stdlib.h>
# include "definitions.h"
# include <fcntl.h>

typedef struct s_img
{
	void	*wall1;
	void	*wall2;
	void	*wall3;
	void	*item;
	void	*hero;
	void	*exit;
	void	*empty;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	t_img	*images;
	char	**map;
}	t_game;

typedef struct s_pos
{
	int	x;
	int	y;
	int	rows;
	int	cols;
}	t_pos;

void	close_window(t_game *game);
void	close_window_message(t_game *game, const char *error);
t_img	*set_up_images(void *mlx_ptr, int w, int h);
void	unload_images(t_game *game);
void	paint(void *mlx, void *mlx_win, t_img *images);
int		handle_key(int keycode, t_game *game);
int		init(t_game *game, char *mapname);
int		map_is_ok(char *path);
int		map_is_reachable(int map_file);

#endif
