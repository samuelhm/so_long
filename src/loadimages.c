/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadimages.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 10:28:11 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/19 13:54:07 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_img	*set_up_images(void *mlx_ptr, int w, int h)
{
	t_img	*images;

	w = GAME_W;
	h = GAME_H;
	images = malloc(sizeof(t_img));
	images->empty = mlx_xpm_file_to_image(mlx_ptr, "./img/empty.xpm", &w, &h);
	if (!images->empty)
		printf("fallo al cargar empty\n");
	images->exit = mlx_xpm_file_to_image(mlx_ptr, "./img/exit.xpm", &w, &h);
	if (!images->exit)
		printf("fallo al cargar exit\n");
	images->hero = mlx_xpm_file_to_image(mlx_ptr, "./img/hero.xpm", &w, &h);
	if (!images->hero)
		printf("fallo al cargar hero\n");
	images->item = mlx_xpm_file_to_image(mlx_ptr, "./img/item.xpm", &w, &h);
	if (!images->item)
		printf("fallo al cargar item\n");
	images->wall1 = mlx_xpm_file_to_image(mlx_ptr, "./img/wall1.xpm", &w, &h);
	if (!images->wall1)
		printf("fallo al cargar wall1\n");
	return (images);
}

void	unload_images(t_game *game)
{
	if (!game || !game->mlx || game->images)
		return ;
	if (game->images->empty)
		mlx_destroy_image(game->mlx, game->images->empty);
	if (game->images->wall1)
		mlx_destroy_image(game->mlx, game->images->wall1);
	if (game->images->hero)
		mlx_destroy_image(game->mlx, game->images->hero);
	if (game->images->exit)
		mlx_destroy_image(game->mlx, game->images->exit);
	if (game->images->item)
		mlx_destroy_image(game->mlx, game->images->item);
	if (game->images)
		free(game->images);
}
