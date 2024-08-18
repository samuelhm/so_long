/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:45:55 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/18 21:19:01 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_CHECKS_H
# define MAP_CHECKS_H

# include "so_long.h"

int		set_player_position_ok(char **map, t_pos *pos);
int		is_valid_move(char **map, t_pos positions, int **visited);
void	dfs(char **map, t_pos *positions, int **visited);
int		check_reachable(char **map, t_pos pos, int **visit);
void	init_moves(int *dx, int *dy);
#endif
