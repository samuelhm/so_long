/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reachable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:34:47 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/20 18:28:03 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/map_checks.h"

static void	free_visited(int **visited, int rows);

static void	init_pos(t_pos *pos)
{
	pos->cols = 0;
	pos->rows = 0;
	pos->x = -1;
	pos->y = -1;
}

static void	init_visit(int **visit, t_pos pos)
{
	int	i;
	int	j;

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

int	map_is_reachable(char *full_map)
{
	char	**map;
	int		**visited;
	t_pos	pos;
	int		result;

	init_pos(&pos);
	map = ft_split(full_map, '\n');
	if (!map)
		return (0);
	while (map[pos.rows])
		pos.rows++;
	pos.cols = ft_strlen(map[0]);
	if (!set_player_position_ok(map, &pos))
		return (0);
	visited = malloc(sizeof(int *) * pos.rows);
	init_visit(visited, pos);
	dfs(map, &pos, visited);
	result = check_reachable(map, pos, visited);
	free_map(map, pos.rows);
	free_visited(visited, pos.rows);
	return (result);
}

static void	free_visited(int **visited, int rows)
{
	int	i;

	if (!visited)
		return ;
	i = 0;
	while (i < rows)
	{
		if (visited[i])
		{
			free(visited[i]);
		}
		i++;
	}
	free(visited);
}

void	free_map(char **map, int rows)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < rows)
	{
		if (map[i])
		{
			free(map[i]);
		}
		i++;
	}
	free(map);
}
