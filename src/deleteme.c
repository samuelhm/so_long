#include <stdlib.h>
#include "../include/so_long.h"

static int	is_valid_move(char **map, int x, int y, int rows, int cols, int **visited)
{
	// Verifica si la posición está dentro de los límites y no es una pared y no ha sido visitada
	return (x >= 0 && x < rows && y >= 0 && y < cols && map[x][y] != '1' && !visited[x][y]);
}

static void	dfs(char **map, int x, int y, int rows, int cols, int **visited)
{
	// Marca la posición actual como visitada
	visited[x][y] = 1;

	// Movimientos posibles: arriba, abajo, izquierda, derecha
	int dx[] = {-1, 1, 0, 0};
	int dy[] = {0, 0, -1, 1};

	// Explora las cuatro direcciones
	for (int i = 0; i < 4; i++)
	{
		int new_x = x + dx[i];
		int new_y = y + dy[i];

		if (is_valid_move(map, new_x, new_y, rows, cols, visited))
		{
			dfs(map, new_x, new_y, rows, cols, visited);
		}
	}
}

static int	map_is_reachable(int map_file)
{
	char	**map;
	int		**visited;
	int		rows = 0;
	int		cols = 0;
	int		player_x = -1, player_y = -1;
	int		all_reachable = 1;

	// Leer el mapa completo en memoria
	map = ft_strsplit_fd(map_file, '\n');  // Supongo que hay una función que separa las líneas del archivo en un array de cadenas
	if (!map)
		return (0);

	// Contar filas y columnas
	while (map[rows])
		rows++;
	cols = ft_strlen(map[0]);

	// Encontrar la posición inicial del jugador
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (map[i][j] == 'P')
			{
				player_x = i;
				player_y = j;
			}
		}
	}

	// Si no se encuentra el jugador, retorno error
	if (player_x == -1 || player_y == -1)
	{
		ft_free_array(map);
		return (0);
	}

	// Inicializar la matriz de visitados
	visited = (int **)malloc(sizeof(int *) * rows);
	for (int i = 0; i < rows; i++)
	{
		visited[i] = (int *)malloc(sizeof(int) * cols);
		for (int j = 0; j < cols; j++)
			visited[i][j] = 0;
	}

	// Iniciar DFS desde la posición del jugador
	dfs(map, player_x, player_y, rows, cols, visited);

	// Verificar que todos los coleccionables y la salida son accesibles
	for (int i = 0; i < rows && all_reachable; i++)
	{
		for (int j = 0; j < cols && all_reachable; j++)
		{
			if ((map[i][j] == 'C' || map[i][j] == 'E') && !visited[i][j])
				all_reachable = 0;
		}
	}

	// Liberar memoria
	for (int i = 0; i < rows; i++)
		free(visited[i]);
	free(visited);
	ft_free_array(map);

	return (all_reachable);
}
