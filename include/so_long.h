/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 22:09:53 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/23 15:17:36 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "libft.h"
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
	int		player_x;
	int		player_y;
	int		win_w;
	int		win_h;
	int		moves;
	int		items;
}	t_game;

typedef struct s_pos
{
	int	x;
	int	y;
	int	rows;
	int	cols;
}	t_pos;

int		close_window(t_game *game);
int		close_window_message(t_game *game, const char *error);
t_img	*set_up_images(void *mlx_ptr, int w, int h);
void	unload_images(t_game *game);
void	paint(t_game *game);
int		handle_key(int keycode, t_game *game);
int		init(t_game *game, char *mapname);
char	**map_is_ok(const char *pathint, int *items);
int		map_is_reachable(char *full_map);
void	get_position(t_game *game);
void	add_print_score(t_game *game);
void	free_map(char **map, int rows);

#endif
