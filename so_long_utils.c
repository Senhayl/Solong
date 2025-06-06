/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouron <mlouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 10:39:47 by mlouron           #+#    #+#             */
/*   Updated: 2025/06/06 09:58:05 by mlouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen_tab(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ciao(t_game *g)
{
	int	i;

	i = 0;
	mlx_destroy_image(g->mlx, g->bush);
	mlx_destroy_image(g->mlx, g->bg);
	mlx_destroy_image(g->mlx, g->carrot);
	mlx_destroy_image(g->mlx, g->exit);
	mlx_destroy_image(g->mlx, g->player->img);
	mlx_destroy_image(g->mlx, g->player->imgd);
	mlx_destroy_image(g->mlx, g->player->imgl);
	mlx_destroy_image(g->mlx, g->player->imgr);
	mlx_destroy_image(g->mlx, g->gg);
	if (g->dim)
		free(g->dim);
	if (g->map)
	{
		while (g->map[i])
			free(g->map[i++]);
		free(g->map);
	}
	if (g->player)
		free(g->player);
	if (g)
		free(g);
	exit(0);
}

int	quit_hook(int keycode, t_game *g)
{
	(void)keycode;
	ciao(g);
	return (0);
}

void	win(t_game *g)
{
	int	la;
	int	lo;

	la = g->dim->la;
	lo = g->dim->lo;
	g->win_status = 1;
	mlx_clear_window(g->mlx, g->win);
	mlx_put_image_to_window(g->mlx, g->win, g->gg, (la * 45), (lo * 45));
	printf("%d", g->count);
	mlx_key_hook(g->win, quit_hook, g);
}

int	key_combo(int keycode, t_game *g)
{
	if (g->win_status == 1)
	{
		if (keycode == XK_Escape)
			ciao(g);
		return (0);
	}
	if (keycode == XK_Escape)
		ciao(g);
	if (keycode == XK_a)
		check_left(g);
	if (keycode == XK_d)
		check_right(g);
	if (keycode == XK_w)
		check_up(g);
	if (keycode == XK_s)
		check_down(g);
	return (1);
}
