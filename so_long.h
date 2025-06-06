/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouron <mlouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:07:30 by mlouron           #+#    #+#             */
/*   Updated: 2025/06/06 17:08:36 by mlouron          ###   ########.fr       */
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
# include	"get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_dim
{
	int		la;
	int		lo;
}				t_dim;

typedef struct s_player
{
	int		x;
	int		y;
	void	*img;
	void	*imgl;
	void	*imgr;
	void	*imgd;
}				t_player;

typedef struct s_game
{
	char		**map;
	void		*exit;
	t_player	*player;
	void		*carrot;
	void		*bush;
	void		*bg;
	t_dim		*dim;
	void		*mlx;
	void		*win;
	void		*gg;
	int			count;
	int			win_status;
	int			map_valid;
	char		last_move;
	int			nbcolleccheck;
	int			collec;
	int			lenx;
	int			leny;
}				t_game;

int		size_map(const char *filename);
char	**map(const char *filename);
void	map_image(t_game *g, int x, int y);
int		ciao(t_game *g);
void	win(t_game *g);
int		key_combo(int keycode, t_game *g);
int		check_map_valid(t_game *g);
int		map_generation(t_game *g);
int		ft_strlen(char *str);
int		ft_strlen_tab(char **s);
void	move_left(t_game *g);
void	move_right(t_game *g);
void	move_up(t_game *g);
void	move_down(t_game *g);
int		check_left(t_game *g);
int		check_right(t_game *g);
int		check_up(t_game *g);
int		check_down(t_game *g);
int		move_on_exit(t_game *g);
int		check_collectibles(t_game *g);
char	*ft_strtrim(char *s1, char *set);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	tag_way(t_game *g, int x, int y, char **visited);
int		check_map_path(t_game *g);
int		check_tag(char **map, int lenx, int leny);
int	lil_map(int fd, char **map, char *line, int i);

#endif