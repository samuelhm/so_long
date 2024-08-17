/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadimages.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 10:28:11 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/17 12:21:14 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_img	*set_up_images(void *mlx_ptr)
{
	t_img	*images;
	char	*path;
	int		i;

	i = 0;
	path = ft_strdup("./img/0.xpm");
	images = malloc(sizeof(t_img) * 4);
	if (!images)
		ft_printf("ERROR IMAGES");
	while (i < 4)
	{
		path[6] = '0' + i;
		ft_printf("El path es: %s", path);
		images[i].path = ft_strdup(path);
		images[i].height = 13;
		images[i].width = 19;
		images[i].imgptr = mlx_xpm_file_to_image(mlx_ptr, path, &images[i].width, &images[i].height);
		if (images[i].imgptr == NULL)
			ft_printf("NULL!!");
		i++;
	}
	free(path);
	return (images);
}
