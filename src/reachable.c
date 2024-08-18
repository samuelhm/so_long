/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reachable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:34:47 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/18 20:15:52 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/map_checks.h"

static void	init_moves(int *dx, int *dy);
static void	init_pos(t_pos pos);
static void	init_visit(char **visit, t_pos pos);

int	map_is_reachable(int map_file)
{
	char	**map;
	int		**visited;
	t_pos	pos;
	int		result;

	init_pos(pos);
	map = ft_split(ft_strfill_fd(map_file), '\n');
	if (!map)
		return (0);
	while (map[pos.rows])
		pos.rows++;
	pos.cols = ft_strlen(map[0]);
	if (!set_player_position_ok(map, pos))
		return (0);
	visited = malloc(sizeof(int *) * pos.rows);
	init_visit(visited, pos);
	dfs(map, pos, visited);
	result = check_reachable(map, pos, visited);
}

static void	init_moves(int *dx, int *dy)
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

static void	init_pos(t_pos pos)
{
	pos.cols = 0;
	pos.rows = 0;
	pos.x = -1;
	pos.y = -1;
}

static void	init_visit(char **visit, t_pos pos)
{
	int	i;
	int j;

	i = 0;


	while (i < pos.rows)
	{
		j = 0;
		visit[i] = malloc(sizeof(int) * pos.cols);
		while (j < pos.cols)
		{
			visit[i][j] = 0;
			j++;
		}
		i++;
	}
}
