/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadimages.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 10:28:11 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/17 17:00:47 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_img	*set_up_images(void *mlx_ptr)
{
	t_img	*images;
	int		w;
	int		h;

	w = GAME_W;
	h = GAME_H;
	images = malloc(sizeof(t_img));
	images->empty = mlx_xpm_file_to_image(mlx_ptr, "./img/empty.xpm", &w, &h);
	images->exit = mlx_xpm_file_to_image(mlx_ptr, "./img/exit.xpm", &w, &h);
	images->hero = mlx_xpm_file_to_image(mlx_ptr, "./img/hero.xpm", &w, &h);
	images->item = mlx_xpm_file_to_image(mlx_ptr, "./img/item.xpm", &w, &h);
	images->wall1 = mlx_xpm_file_to_image(mlx_ptr, "./img/wall1.xpm", &w, &h);
	images->wall2 = mlx_xpm_file_to_image(mlx_ptr, "./img/wall2.xpm", &w, &h);
	images->wall3 = mlx_xpm_file_to_image(mlx_ptr, "./img/wall3.xpm", &w, &h);

	return (images);
}

void unload_images(t_game *game)
{
	mlx_destroy_image(game->mlx, game->images->empty);
	mlx_destroy_image(game->mlx, game->images->wall1);
	mlx_destroy_image(game->mlx, game->images->wall2);
	mlx_destroy_image(game->mlx, game->images->wall3);
	mlx_destroy_image(game->mlx, game->images->hero);
	mlx_destroy_image(game->mlx, game->images->exit);
	mlx_destroy_image(game->mlx, game->images->item);
}
