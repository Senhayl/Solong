/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouron <mlouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:48:19 by mlouron           #+#    #+#             */
/*   Updated: 2025/05/30 18:10:33 by mlouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	CheckLeft(t_game *g)
{
	int	x;
	int	y;

	x = g->player->x;
	y = g->player->y;
	if (x <= 0 || g->map[y][x - 1]== '1')
		return (0);
	MoveLeft(g);
	return (1);
}

int	CheckRight(t_game *g)
{
	int	x;
	int	y;

	x = g->player->x;
	y = g->player->y;
	if (x >= g->dim->la - 1 || g->map[y][x  + 1]== '1')
		return (0);
	MoveRight(g);
	return (1);
}

int	CheckUp(t_game *g)
{
	int	x;
	int	y;

	x = g->player->x;
	y = g->player->y;
	if (y <= 0 || g->map[y - 1][x] == '1')
		return (0);
	MoveUp(g);
	return (1);
}

int	CheckDown(t_game *g)
{
	int	x;
	int	y;

	x = g->player->x;
	y = g->player->y;
	if (y >= g->dim->lo - 1 || g->map[y + 1][x] == '1')
		return (0);
	MoveDown(g);
	return (1);
}

