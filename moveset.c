/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouron <mlouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:54:09 by mlouron           #+#    #+#             */
/*   Updated: 2025/06/06 09:49:01 by mlouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_game *g)
{
	int	x;
	int	y;

	x = g->player->x;
	y = g->player->y;
	if (move_on_exit(g))
		g->map[y][x] = '0';
	if (move_on_exit(g) == 0)
		g->map[y][x] = 'E';
	g->map[y][x - 1] = 'P';
	g->player->x--;
	g->count++;
	g->last_move = 'l';
	map_generation(g);
}

void	move_right(t_game *g)
{
	int	x;
	int	y;

	x = g->player->x;
	y = g->player->y;
	if (move_on_exit(g) == 1)
		g->map[y][x] = '0';
	if (move_on_exit(g) == 0)
		g->map[y][x] = 'E';
	g->map[y][x + 1] = 'P';
	g->player->x++;
	g->count++;
	g->last_move = 'r';
	map_generation(g);
}

void	move_up(t_game *g)
{
	int	x;
	int	y;

	x = g->player->x;
	y = g->player->y;
	if (move_on_exit(g) == 1)
		g->map[y][x] = '0';
	if (move_on_exit(g) == 0)
		g->map[y][x] = 'E';
	g->map[y - 1][x] = 'P';
	g->player->y--;
	g->count++;
	g->last_move = 'u';
	map_generation(g);
}

void	move_down(t_game *g)
{
	int	x;
	int	y;

	x = g->player->x;
	y = g->player->y;
	if (move_on_exit(g) == 1)
		g->map[y][x] = '0';
	if (move_on_exit(g) == 0)
		g->map[y][x] = 'E';
	g->map[y + 1][x] = 'P';
	g->player->y++;
	g->count++;
	g->last_move = 'd';
	map_generation(g);
}

int	move_on_exit(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (y != g->dim->lo)
	{
		x = 0;
		while (x != g->dim->la)
		{
			if (g->map[y][x] == 'E')
			{
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
