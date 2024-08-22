/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 23:09:52 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/22 12:00:10 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	map_line_is_ok(const char *s, int line, int i);
static int	map_is_rect_fenced(char *full_map, int row, int col);
static int	result_ok(char *mapline, int col, int row, char **map);
static int	map_got_all_items(char *full_map);

char	**map_is_ok(const char *path, int *items)
{
	int		map_checks[3];
	int		map_file;
	char	*full_map;
	char	**result;

	map_file = open(path, 0);
	full_map = ft_strfill_fd(map_file);
	close(map_file);
	map_checks[0] = map_is_rect_fenced(full_map, 1, 0);
	map_checks[1] = map_got_all_items(full_map);
	*items = map_checks[1];
	map_checks[2] = map_is_reachable(full_map);
	if ((map_checks[0] + map_checks[2] + (map_checks[1] > 0)) == 3)
	{
		result = ft_split(full_map, '\n');
		free(full_map);
		return (result);
	}
	free(full_map);
	return (NULL);
}

static int	map_is_rect_fenced(char *full_map, int row, int col)
{
	char	**map;
	int		i;

	map = ft_split(full_map, '\n');
	if (!map[0])
		return (0);
	col = ft_strlen(map[0]);
	if (!map_line_is_ok(map[0], 0, 0))
	{
		return (0);
	}
	i = 1;
	while (map[i])
	{
		if (col != ft_strlen(map[i]) || !map_line_is_ok(map[i], 1, 0))
		{
			ft_free_2d_array((void **)map);
			return (0);
		}
		row++;
		i++;
	}
	return (result_ok(map[i - 1], col, row, map));
}

static int	map_line_is_ok(const char *s, int line, int i)
{
	if (!s)
		return (0);
	if (line == 0 || line == 2)
	{
		while (s[i])
		{
			if (s[i] != '1')
				return (0);
			i++;
		}
	}
	else if (line == 1)
	{
		while (s[i])
		{
			if (s[i] != '0' && s[i] != '1' && s[i] != 'C'
				&& s[i] != 'E' && s[i] != 'P')
				return (0);
			i++;
		}
		if (s[i - 1] != '1' || s[0] != '1')
			return (0);
	}
	return (1);
}

static int	result_ok(char *mapline, int col, int row, char **map)
{
	if (col > 2 && row > 2 && map_line_is_ok(mapline, 2, 0))
	{
		ft_free_2d_array((void **)map);
		return (1);
	}
	ft_free_2d_array((void **)map);
	return (0);
}

static int	map_got_all_items(char *full_map)
{
	int		i;
	int		player;
	int		items;
	int		exit;

	i = 0;
	player = 0;
	items = 0;
	exit = 0;
	while (full_map[i])
	{
		if (full_map[i] == 'P')
			player++;
		if (full_map[i] == 'E')
			exit++;
		if (full_map[i] == 'C')
			items++;
		i++;
	}
	if (player == 1 && exit == 1 && items > 0)
		return (items);
	return (0);
}
