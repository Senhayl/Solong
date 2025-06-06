/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouron <mlouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 10:35:13 by mlouron           #+#    #+#             */
/*   Updated: 2025/06/06 17:11:44 by mlouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	size_map(const char *filename)
{
	int		fd;
	char	*line;
	int		i;
	int		size;

	i = 0;
	size = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		size++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (size);
}

char	**map(const char *filename)
{
	char	**map;
	int		size;
	char	*line;
	int		fd;
	int		i;

	size = size_map(filename);
	map = malloc(sizeof(char *) * (size + 1));
	if (!map)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (free(map), NULL);
	i = 0;
	line = get_next_line(fd);
	i = lil_map(fd, map, line, i);
	map[i] = NULL;
	close(fd);
	return (map);
}

int	lil_map(int fd, char **map, char *line, int i)
{
	while (line)
	{
		map[i] = ft_strtrim(line, "\n");
		free(line);
		if (!map[i])
		{
			while (i > 0)
				free(map[--i]);
			return (free(map), close(fd), 0);
		}
		i++;
		line = get_next_line(fd);
	}
	return (i);
}

int	check_map_valid(t_game *g)
{
	int	x;
	int	y;
	int	exit;
	int	player;

	g->lenx = ft_strlen(g->map[0]);
	g->leny = ft_strlen_tab(g->map);
	g->collec = 0;
	player = 0;
	exit = 0;
	y = 0;
	while (y < g->leny)
	{
		x = 0;
		while (x < g->lenx)
		{
			if (y == 0 || y == g->leny - 1 || x == 0 || x == g->lenx - 1)
			{
				if (g->map[y][x] != '1')
				{
					g->map_valid = 0;
					return (0);
				}
			}
			if (g->map[y][x] == 'P')
			{
				player++;
				g->player->x = x;
				g->player->y = y;
			}
			if (g->map[y][x] == 'E')
				exit++;
			if (g->map[y][x] == 'C')
				g->collec++;
			x++;
		}
		y++;
	}
	if (check_map_path(g) == 0)
		return (0);
	if (player != 1 || exit != 1 || g->collec == 0)
		return (g->map_valid = 0);
	g->map_valid = 1;
	return (1);
}
