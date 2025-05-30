/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouron <mlouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:07:35 by mlouron           #+#    #+#             */
/*   Updated: 2025/05/30 17:23:39 by mlouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_all(t_game *g)
{
	int	w;
	int	h;

	g->map = map();
	g->dim->la = ft_strlen(g->map[0]);
	g->dim->lo = ft_strlen_tab(g->map);
	g->carrot = mlx_xpm_file_to_image(g->mlx, "img/carrot.xpm", &w, &h);
	g->player->img = mlx_xpm_file_to_image(g->mlx, "img/rabbit.xpm", &w, &h);
	g->exit = mlx_xpm_file_to_image(g->mlx, "img/exit.xpm", &w, &h);
	g->bush = mlx_xpm_file_to_image(g->mlx, "img/bush.xpm", &w, &h);
	g->bg = mlx_xpm_file_to_image(g->mlx, "img/dirt.xpm", &w, &h);
}

int	map_generation(t_game *g, int	zboub)
{
	int	x;
	int	y;

	y = 0;
	while (y != g->dim->lo)
	{
		x = 0;
		while (x != g->dim->la)
		{
			if (g->map[y][x] == '1')
				mlx_put_image_to_window(g->mlx, g->win, g->bush, x * T_S, y * T_S);
			if (g->map[y][x] == 'E')
				mlx_put_image_to_window(g->mlx, g->win, g->exit, x * T_S, y * T_S);
			if (g->map[y][x] == 'P')
			{
				if (zboub == 1)
				{
					g->player->x = x;
					g->player->y = y;
				}
				mlx_put_image_to_window(g->mlx, g->win, g->player->img, x * T_S, y * T_S);
			}
			if (g->map[y][x] == '0')
				mlx_put_image_to_window(g->mlx, g->win, g->bg, x * T_S, y * T_S);
			if (g->map[y][x] == 'C')
				mlx_put_image_to_window(g->mlx, g->win, g->carrot, x * T_S, y * T_S);
			x++;
		}
		y++;
	}
	return (1);
}

int	ciao(t_game *g)
{
	mlx_destroy_window(g->mlx, g->win);
	exit(0);
}

int	key_combo(int keycode, t_game *g)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(g->mlx, g->win);
		exit(0);
	}
	if (keycode == XK_q)
		CheckLeft(g);
	if (keycode == XK_d)
		CheckRight(g);
	if (keycode == XK_w)
		CheckUp(g);
	if (keycode == XK_s)
		CheckDown(g);
	return (1);
}

int	main(void)
{
	t_game	*g;
	
	g = malloc(sizeof(t_game));
	g->dim = malloc(sizeof(t_dim));
	g->player = malloc(sizeof(t_player));
	g->mlx = mlx_init();
	init_all(g);
	g->win = mlx_new_window(g->mlx, (g->dim->la * 100), (g->dim->lo * 100), "rabbit");
	map_generation(g, 1);
	mlx_key_hook(g->win, key_combo, g);
	mlx_hook(g->win, DestroyNotify, StructureNotifyMask, ciao, g);
	mlx_loop(g->mlx);
}