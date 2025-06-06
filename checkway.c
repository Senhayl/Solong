/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkway.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouron <mlouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 09:58:53 by mlouron           #+#    #+#             */
/*   Updated: 2025/06/06 16:52:45 by mlouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	tag_way(t_game *g, int x, int y, char **visited)
{
	if (g->map[y][x] == '1' || visited[y][x] == 'O')
		return ;
	visited[y][x] = 'O';
	tag_way(g, x + 1, y, visited);
	tag_way(g, x - 1, y, visited);
	tag_way(g, x, y + 1, visited);
	tag_way(g, x, y - 1, visited);
}

int	check_map_path(t_game *g)
{
	char	**visited;
	int		i;
	int		result;

	visited = malloc(sizeof(char *) * g->leny);
	if (!visited)
		return (0);
	i = -1;
	while (++i < g->leny)
	{
		visited[i] = strdup(g->map[i]);
		if (!visited[i])
		{
			while (i-- > 0)
				free(visited[i]);
			return (free(visited), 0);
		}
	}
	tag_way(g, g->player->x, g->player->y, visited);
	result = check_tag(visited, g->lenx, g->leny);
	while (g->leny--)
		free(visited[g->leny]);
	return (free(visited), result);
}

int	check_tag(char **map, int lenx, int leny)
{
	int		i;
	int		j;

	i = 0;
	while (i < leny)
	{
		j = 0;
		while (j < lenx)
		{
			if (map[i][j] == 'E' || map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
