/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouron <mlouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:48:19 by mlouron           #+#    #+#             */
/*   Updated: 2025/06/05 17:57:10 by mlouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_left(t_game *g)
{
	int	x;
	int	y;

	x = g->player->x;
	y = g->player->y;
	if (g->map[y][x - 1] == '1')
		return (0);
	move_left(g);
	return (1);
}

int	check_right(t_game *g)
{
	int	x;
	int	y;

	x = g->player->x;
	y = g->player->y;
	if (g->map[y][x + 1] == '1')
		return (0);
	move_right(g);
	return (1);
}

int	check_up(t_game *g)
{
	int	x;
	int	y;

	x = g->player->x;
	y = g->player->y;
	if (g->map[y - 1][x] == '1')
		return (0);
	move_up(g);
	return (1);
}

int	check_down(t_game *g)
{
	int	x;
	int	y;

	x = g->player->x;
	y = g->player->y;
	if (g->map[y + 1][x] == '1')
		return (0);
	move_down(g);
	return (1);
}

int	check_collectibles(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (y != g->dim->lo)
	{
		x = 0;
		while (x != g->dim->la)
		{
			if (g->map[y][x] == 'C')
			{
				return (1);
			}
			x++;
		}
		y++;
	}
	if (move_on_exit(g) == 0)
		return (0);
	return (1);
}
