/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 23:09:52 by shurtado          #+#    #+#             */
/*   Updated: 2024/08/18 18:42:45 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	map_line_is_ok(const char *s, int line);
static int	map_is_rect_fenced(int map, int row, int col);
static int	result_ok(char *mapline, int col, int row);
static int	map_got_all_items(int map_file);

int	map_is_ok(char *path)
{
	int	map_checks[3];
	int	map_file;

	map_file = open(path, 0);
	map_checks[0] = (map_is_rect_fenced(map_file, 0, 0));
	close(map_file);
	map_file = open(path, 0);
	map_checks[1] = map_got_all_items(map_file);
	close(map_file);
	map_file = open(path, 0);
	map_checks[2] = map_is_reachable(map_file);
	close(map_file);
	return ((map_checks[0] + map_checks[1] + map_checks[2]) == 3);
}

static int	map_is_rect_fenced(int map, int row, int col)
{
	char	*mapline;
	char	*nextline;

	mapline = get_next_line(map);
	if (!mapline)
		return (0);
	col = ft_strlen(mapline);
	row++;
	if (!map_line_is_ok(mapline, 0))
		return (0);
	nextline = get_next_line(map);
	while (nextline)
	{
		free (mapline);
		mapline = nextline;
		nextline = get_next_line(map);
		if (col != ft_strlen(mapline) || !map_line_is_ok(mapline, 1))
		{
			free(mapline);
			return (0);
		}
		row++;
	}
	return (result_ok(mapline, col, row));
}

static int	map_line_is_ok(const char *s, int line)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
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
		if (s[0] != '1')
			return (0);
		while (s[i])
			i++;
		if (s[i - 1] != '1')
			return (0);
	}
	return (1);
}

static int	result_ok(char *mapline, int col, int row)
{
	if (col > 2 && row > 2 && map_line_is_ok(mapline, 2))
	{
		free (mapline);
		return (1);
	}
	free (mapline);
	return (0);
}

static int	map_got_all_items(int map_file)
{
	char	*full_map;
	int		i;
	int		player;
	int		items;
	int		exit;

	i = 0;
	player = 0;
	items = 0;
	exit = 0;
	full_map = ft_strfill_fd(map_file);
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
	free(full_map);
	if (player == 1 && exit == 1 && items > 0)
		return (1);
	return (0);
}
