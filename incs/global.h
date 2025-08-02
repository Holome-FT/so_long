/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 00:49:10 by raamayri          #+#    #+#             */
/*   Updated: 2025/08/02 21:57:47 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

# include "../Libft/incs/libft.h"
# include "../Libft/incs/get_next_line.h"
# include "../Libft/incs/ft_printf.h"
# include "../Libft/incs/ft_dprintf.h"
# include "../Libft/incs/ft_sprintf.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <sys/time.h>
# include <errno.h>
# include <fcntl.h>
# include <string.h>
# include <stdbool.h>
# include <limits.h>

typedef enum e_game_state
{
	GAME_START,
	GAME_WAIT_1,
	GAME_ONGOING,
	GAME_WIN,
	GAME_LOSE,
	GAME_WAIT_2,
	GAME_EXIT,
}	t_game_state;

typedef enum e_player_state
{
	PLAYER_DEFAULT,
	PLAYER_POWERED,
	PLAYER_DYING,
	PLAYER_DEAD,
}	t_player_state;

typedef enum e_player_dirct
{
	PLAYER_RIGHT,
	PLAYER_LEFT,
	PLAYER_UP,
	PLAYER_DOWN,
}	t_player_dirct;

typedef struct s_player
{
	t_player_state	state;
	t_player_dirct	dirct[2];
	long long		s_xy[2];
	long long		xy[2];
	int				speed;
	int				score;
	struct s_player	*prev;
	struct s_player	*next;
}					t_player;

typedef enum e_ghost_state
{
	GHOST_DEFAULT,
	GHOST_SCATTER,
	GHOST_SCARED,
	GHOST_DEAD,
}	t_ghost_state;

typedef enum e_ghost_type
{
	GHOST_BLINKY,
	GHOST_PINKY,
	GHOST_INKY,
	GHOST_CLYDE,
}	t_ghost_type;

typedef struct s_ghost
{
	t_ghost_state	state;
	t_ghost_type	type;
	long long		s_xy[2];
	long long		xy[2];
	int				speed;
	struct s_ghost	*prev;
	struct s_ghost	*next;
}					t_ghost;

typedef enum e_pellet_state
{
	PELLET_DEFAULT,
	PELLET_POWERED,
	PELLET_DEAD,
}	t_pellet_state;

typedef struct s_pellet
{
	t_pellet_state	s_state;
	t_pellet_state	state;
	long long		xy[2];
	struct s_pellet	*prev;
	struct s_pellet	*next;
}					t_pellet;

typedef struct s_map
{
	int				fd;
	char			**data;
	long long		wh[2];
	t_player		*players;
	t_ghost			*ghosts;
	t_pellet		*pellets;
	struct s_map	*prev;
	struct s_map	*next;
}					t_map;

typedef struct s_flags
{
	bool	loop;
	bool	force;
	bool	debug;
}			t_flags;

typedef struct s_window
{
	void		*ptr;
	long long	wh[2];
}				t_window;

typedef struct s_asset
{
	void		*ptr;
	char		*pda;
	long long	wh[2];
	int			bpp;
	int			bpl;
	int			eda;
}				t_asset;

typedef struct s_assets
{
	t_asset	*pacman;
	t_asset	*pacman_dead;
	t_asset	*ghosts;
	t_asset	*pellets;
	t_asset	*walls;
	t_asset	*exit;
}			t_assets;

typedef struct s_mlx
{
	void		*ptr;
	t_window	*win;
	t_assets	*assets;
	t_asset		*buffer;
}				t_mlx;

typedef struct s_game
{
	t_game_state		state;
	t_map				**maps;
	t_map				*map;
	t_flags				*flags;
	t_mlx				*mlx;
	int					lives;
	int					score;
	int					moves;
	struct timeval		old_time;
}						t_game;

typedef struct s_queue_node
{
	long long			x;
	long long			y;
	struct s_queue_node	*next;
}						t_queue_node;

typedef struct s_queue
{
	t_queue_node	*front;
	t_queue_node	*rear;
}					t_queue;

typedef struct s_prt_tile
{
	long long	x;
	long long	y;
}				t_prt_tile;

typedef struct s_bfs
{
	t_prt_tile	*prt;
	bool		*vst;
	t_map		*map;
}				t_bfs;

void			ft_free_array(void ***array);
void			ft_free_maps(t_map **maps);

void			ft_error(int id, const char *msg);

void			ft_flag_switch(t_map **maps, t_flags *opts, const char *flag);

int				ft_init_map(t_map *map);
int				ft_addnew_map(t_map **maps, const char *path);
bool			**ft_alloc_mask(t_map *map);

bool			ft_isvalid_maps(t_map **maps);
bool			ft_isfinishable_maps(t_map **maps);

void			ft_load_game(t_map **maps, t_flags *opts);

void			ft_game_over(t_game *game);
void			ft_exit_game(t_game *game);
void			ft_reset_map(t_game *game, bool force);
void			ft_kill_pacman(t_game *game);
void			ft_close_win(t_game *game, int sleep_time);
void			ft_open_win(t_game *game);
int				ft_stop_game(void *param);
t_mlx			*ft_init_mlx(void);
void			ft_game_error(int id, const char *msg, t_game *game);
int				ft_load_ast(t_mlx *mlx, t_asset *ast, char *ast_path);
void			ft_free_assets(t_mlx *mlx, t_assets *asts);
void			ft_debug_key_switch_1(int keycode, t_game *game);
void			ft_debug_key_switch_2(int keycode, t_game *game);

void			ft_draw_game(t_game *game, int sleep_time);
void			ft_clear_buffer(t_asset *buffer);
void			ft_draw_asset_into_buffer(t_asset *buffer, int xy[2],
					t_asset *asset, int xywh[4]);
void			ft_put_pixel_into_buffer(t_asset *buffer,
					unsigned int color, int xy[2]);
void			ft_draw_ghosts(t_game *game);
void			ft_draw_pacman(t_game *game);
size_t			ft_draw_pellets(t_game *game);
void			ft_draw_exit(t_game *game);
void			ft_draw_walls(t_game *game);
void			ft_draw_info(t_game *game);

int				ft_calc_game(t_game *game);
void			ft_calc_player(t_game *game);
void			ft_calc_ghosts(t_game *game, long long nb_pellets);
long long		ft_calc_pellets(t_game *game);
bool			ft_isvalid_move(t_map *map, long long tblr[4]);
void			ft_calc_clyde_move(t_map *map, t_ghost *ghost,
					long long new_xy[4]);
void			ft_calc_inky_move(t_map *map, t_ghost *ghost,
					long long new_xy[4]);
void			ft_calc_pinky_move(t_map *map, t_ghost *ghost,
					long long new_xy[4]);
void			ft_calc_blinky_move(t_map *map, t_ghost *ghost,
					long long new_xy[4]);
void			ft_calc_ghost_move(t_game *game, t_ghost *ghost,
					long long new_xy[4]);

int				ft_bfs(t_map *map, long long new_xy[4], long long trg_xy[2]);
int				ft_init_bfs(t_bfs **bfs, t_map *map);
void			ft_find_next_step(long long mgc_nb[5],
					long long *result_xy, t_bfs *bfs);
void			ft_free_queue(t_queue *queue);
t_queue_node	*ft_dequeue(t_queue *queue);
void			ft_enqueue(t_queue *queue, long long xy[2]);
t_queue_node	*ft_new_queue_node(long long x, long long y);

#endif
