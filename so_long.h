/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouron <mlouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:07:30 by mlouron           #+#    #+#             */
/*   Updated: 2025/05/30 17:17:00 by mlouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef T_S
#  define T_S 100
# endif

# include	"minilibx-linux/mlx.h"
# include	"minilibx-linux/mlx_int.h"
# include	<X11/X.h>
# include	<X11/keysym.h>

typedef struct s_dim
{
	int		la;
	int		lo;
}				t_dim;

typedef struct s_player
{
	int	x;
	int	y;
	void *img;
}				t_player;



typedef struct s_game
{
	char	**map;
	void		*exit;
	t_player	*player;
	void		*carrot;
	void		*bush;
	void		*bg;
	t_dim		*dim;
	void		*mlx;
	void		*win;
}				t_game;

char	**map(void);
int		map_generation(t_game *g, int zboub);
int		ft_strlen(char *str);
int		ft_strlen_tab(char **s);
void	MoveLeft(t_game *g);
void	MoveRight(t_game *g);
void	MoveUp(t_game *g);
void	MoveDown(t_game *g);
int		CheckLeft(t_game *g);
int		CheckRight(t_game *g);
int		CheckUp(t_game *g);
int		CheckDown(t_game *g);

#endif