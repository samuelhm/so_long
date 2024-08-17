/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 22:09:53 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/17 10:49:07 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <stdlib.h>

typedef struct s_img
{
	void	*imgptr;
	int		width;
	int		height;
	char	*path;
}				t_img;

int		close_window(void);
t_img	*set_up_images(void *mlx_ptr);

#endif
