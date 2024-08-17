/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 22:09:53 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/17 21:58:15 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <stdlib.h>
# include "definitions.h"

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
}	t_game;


int		close_window(t_game *game);
t_img	*set_up_images(void *mlx_ptr, int w, int h);
void	unload_images(t_game *game);
void	paint(void *mlx, void *mlx_win, t_img *images);
int		handle_key(int keycode, t_game *game);
int		init(t_game *game);

#endif
