/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouron <mlouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:54:09 by mlouron           #+#    #+#             */
/*   Updated: 2025/05/30 17:16:45 by mlouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	MoveLeft(t_game *g)
{
	int x; 
	int y;
	
	x = g->player->x;
	y = g->player->y;
	g->map[y][x] = '0';  
	g->map[y][x - 1] = 'P';
	g->player->x--;
	map_generation(g, 0);
}

void	MoveRight(t_game *g)
{
	int x; 
	int y;
	
	x = g->player->x;
	y = g->player->y;
	g->map[y][x] = '0';  
	g->map[y][x + 1] = 'P';
	g->player->x++;
	map_generation(g, 0);
}

void	MoveUp(t_game *g)
{
	int x; 
	int y;
	
	x = g->player->x;
	y = g->player->y;
	g->map[y][x] = '0';  
	g->map[y - 1][x] = 'P';
	g->player->y--;
	map_generation(g, 0);
}

void	MoveDown(t_game *g)
{
	int x; 
	int y;
	
	x = g->player->x;
	y = g->player->y;
	g->map[y][x] = '0';  
	g->map[y + 1][x] = 'P';
	g->player->y++;
	map_generation(g, 0);
}


