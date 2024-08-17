/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paintwindows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:23:29 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/17 15:30:34 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void paint(void *mlx, void *mlx_win, t_img *images)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 640)
	{
		j = 0;
		while (j < 640)
		{
			mlx_put_image_to_window(mlx, mlx_win, images->empty, i, j);
			j += 32;
		}
		i += 32;
	}
}
