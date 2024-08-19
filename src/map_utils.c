/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:49:01 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/19 14:47:19 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/map_checks.h"

int	set_player_position_ok(char **map, t_pos *pos)
{
	int	i;
	int	j;

	i = 0;
	while (i < pos->rows)
	{
		j = 0;
		while (j < pos->cols)
		{
			if (map[i][j] == 'P')
			{
				pos->x = i;
				pos->y = j;
			}
			j++;
		}
		i++;
	}
	if (pos->x == -1 || pos->y == -1)
	{
		ft_free_2d_array((void **)map);
		return (0);
	}
	return (1);
}

int	is_valid_move(char **map, t_pos positions, int **visited)
{
	if (!(positions.x >= 0 && positions.x < positions.rows))
		return (0);
	if (!(positions.y >= 0 && positions.y < positions.cols))
		return (0);
	if (map[positions.x][positions.y] == '1' )
		return (0);
	return (!visited[positions.x][positions.y]);
}

void	dfs(char **map, t_pos *pos, int **visited)
{
	int		dx[4];
	int		dy[4];
	int		i;
	t_pos	newpos;

	i = 0;
	init_moves(dx, dy);
	visited[pos->x][pos->y] = 1;
	while (i < 4)
	{
		newpos = *pos;
		newpos.x += dx[i];
		newpos.y += dy[i];
		if (is_valid_move(map, newpos, visited))
			dfs(map, &newpos, visited);
		i++;
	}
}

int	check_reachable(char **map, t_pos pos, int **visit)
{
	int	i;
	int	j;

	i = 0;
	while (i < pos.rows)
	{
		j = 0;
		while (j < pos.cols)
		{
			if ((map[i][j] == 'C' || map[i][j] == 'E') && !visit[i][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	init_moves(int *dx, int *dy)
{
	dx[0] = -1;
	dx[1] = 1;
	dx[2] = 0;
	dx[3] = 0;
	dy[0] = 0;
	dy[1] = 0;
	dy[2] = -1;
	dy[3] = 1;
}
