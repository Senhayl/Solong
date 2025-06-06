/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouron <mlouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:07:35 by mlouron           #+#    #+#             */
/*   Updated: 2025/06/06 10:18:10 by mlouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_all(t_game *g, char *filename)
{
	int	w;
	int	h;

	g->map = map(filename);
	check_map_valid(g);
	if (g->map_valid == 0)
	{
		free(g->map);
		return (0);
	}
	g->dim->la = ft_strlen(g->map[0]);
	g->dim->lo = ft_strlen_tab(g->map);
	g->carrot = mlx_xpm_file_to_image(g->mlx, "img/carrot.xpm", &w, &h);
	g->gg = mlx_xpm_file_to_image(g->mlx, "img/win.xpm", &w, &h);
	g->player->img = mlx_xpm_file_to_image(g->mlx, "img/rabbit.xpm", &w, &h);
	g->player->imgl = mlx_xpm_file_to_image(g->mlx, "img/rabbit_l.xpm", &w, &h);
	g->player->imgr = mlx_xpm_file_to_image(g->mlx, "img/rabbit_r.xpm", &w, &h);
	g->player->imgd = mlx_xpm_file_to_image(g->mlx, "img/rabbit_d.xpm", &w, &h);
	g->exit = mlx_xpm_file_to_image(g->mlx, "img/exit.xpm", &w, &h);
	g->bush = mlx_xpm_file_to_image(g->mlx, "img/bush.xpm", &w, &h);
	g->bg = mlx_xpm_file_to_image(g->mlx, "img/dirt.xpm", &w, &h);
	return (1);
}

int	map_generation(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	if (check_collectibles(g) == 0)
	{
		win(g);
		return (1);
	}
	while (y != g->dim->lo)
	{
		x = 0;
		while (x != g->dim->la)
		{
			map_image(g, x, y);
			x++;
		}
		y++;
	}
	return (1);
}

void	map_image(t_game *g, int x, int y)
{
	if (g->map[y][x] == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->bush, x * T_S, y * T_S);
	if (g->map[y][x] == 'E')
		mlx_put_image_to_window(g->mlx, g->win, g->exit, x * T_S, y * T_S);
	if (g->map[y][x] == 'P')
	{
		if (g->last_move == 'u' || g->last_move == 0)
			mlx_put_image_to_window(g->mlx, g->win, g->player->img, x * T_S, y * T_S);
		if (g->last_move == 'l')
			mlx_put_image_to_window(g->mlx, g->win, g->player->imgl, x * T_S, y * T_S);
		if (g->last_move == 'r')
			mlx_put_image_to_window(g->mlx, g->win, g->player->imgr, x * T_S, y * T_S);
		if (g->last_move == 'd')
			mlx_put_image_to_window(g->mlx, g->win, g->player->imgd, x * T_S, y * T_S);
	}
	if (g->map[y][x] == '0')
		mlx_put_image_to_window(g->mlx, g->win, g->bg, x * T_S, y * T_S);
	if (g->map[y][x] == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->carrot, x * T_S, y * T_S);
}

int	main(int ac, char **av)
{
	t_game	*g;

	if (ac != 2)
		return (write(2, "Need map.ber in second argument\n", 33));
	g = malloc(sizeof(t_game));
	if (!g)
		return (0);
	ft_bzero(g, sizeof(t_game));
	g->dim = malloc(sizeof(t_dim));
	g->player = malloc(sizeof(t_player));
	if (!g->dim || !g->player)
		return (free(g->dim), free(g->player), free(g), 1);
	g->last_move = 0;
	g->count = 0;
	g->mlx = mlx_init();
	if (!init_all(g, av[1]))
		return (free(g->player), free(g->dim), free(g), write(1, "Error\nmap not valid", 20));
	g->win = mlx_new_window(g->mlx, (g->dim->la * 100), (g->dim->lo * 100), "rabbit");
	map_generation(g);
	mlx_key_hook(g->win, key_combo, g);
	mlx_hook(g->win, DestroyNotify, StructureNotifyMask, ciao, g);
	mlx_loop(g->mlx);
}
