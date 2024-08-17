/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 22:09:45 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/17 10:45:12 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"



int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_img	*images;


	mlx = mlx_init();
	images = set_up_images(mlx);
	mlx_win = mlx_new_window(mlx, 800, 600, "Hello world!");
	mlx_put_image_to_window(mlx, mlx_win, images[0].imgptr, 10, 10);
	mlx_hook(mlx_win, 17, 0, close_window, NULL);
	mlx_loop(mlx);
	return (0);
}
