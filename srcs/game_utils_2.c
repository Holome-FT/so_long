/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:44:12 by raamayri          #+#    #+#             */
/*   Updated: 2025/08/02 19:25:05 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/global.h"

int	ft_init_bfs(t_bfs **bfs, t_map *map)
{
	size_t	calc;

	*bfs = ft_calloc(1, sizeof(t_bfs));
	if (!*bfs)
		return (-1);
	(*bfs)->map = map;
	calc = map->wh[0] * (*bfs)->map->wh[1];
	(*bfs)->prt = ft_calloc(calc, sizeof(t_prt_tile));
	if (!(*bfs)->prt)
		return (free(*bfs), -1);
	(*bfs)->vst = ft_calloc(calc, sizeof(bool));
	if (!(*bfs)->vst)
		return (free((*bfs)->prt), free(*bfs), -1);
	return (0);
}

static int	ft_key_switch(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == XK_Escape)
		ft_stop_game(param);
	else if (keycode == XK_w || keycode == XK_Up)
		game->map->players->dirct[1] = PLAYER_UP;
	else if (keycode == XK_a || keycode == XK_Left)
		game->map->players->dirct[1] = PLAYER_LEFT;
	else if (keycode == XK_s || keycode == XK_Down)
		game->map->players->dirct[1] = PLAYER_DOWN;
	else if (keycode == XK_d || keycode == XK_Right)
		game->map->players->dirct[1] = PLAYER_RIGHT;
	else if (game->flags->debug)
	{
		ft_debug_key_switch_1(keycode, game);
		ft_debug_key_switch_2(keycode, game);
	}
	return (0);
}

static void	ft_make_win(t_game	*game)
{
	char		title[128];
	static int	level = 1;

	ft_sprintf(title, "Pac-Man - Level %d", level);
	if (level < INT_MAX)
		level++;
	game->mlx->win->ptr = mlx_new_window(game->mlx->ptr,
			game->mlx->win->wh[0],
			game->mlx->win->wh[1],
			title);
	if (!game->mlx->win->ptr)
		ft_exit_game(game);
	game->mlx->buffer->ptr = mlx_new_image(game->mlx->ptr,
			game->mlx->win->wh[0],
			game->mlx->win->wh[1]);
	if (!game->mlx->buffer->ptr)
		ft_exit_game(game);
	game->mlx->buffer->pda = mlx_get_data_addr(game->mlx->buffer->ptr,
			&game->mlx->buffer->bpp,
			&game->mlx->buffer->bpl,
			&game->mlx->buffer->eda);
	if (!game->mlx->buffer->pda)
		ft_exit_game(game);
}

void	ft_open_win(t_game *game)
{
	int	screen_wh[2];

	game->mlx->win->wh[0] = game->map->wh[0] * 16;
	game->mlx->win->wh[1] = game->map->wh[1] * 16 + 96;
	game->mlx->buffer->wh[0] = game->mlx->win->wh[0];
	game->mlx->buffer->wh[1] = game->mlx->win->wh[1];
	mlx_get_screen_size(game->mlx->ptr, &screen_wh[0], &screen_wh[1]);
	if (!game->flags->force && \
		(game->mlx->win->wh[0] > (long long)screen_wh[0] || \
		game->mlx->win->wh[1] + 144 > (long long)screen_wh[1]))
		ft_game_error(EFBIG, "Map too big. Use --force to ignore.", game);
	ft_make_win(game);
	mlx_hook(game->mlx->win->ptr, DestroyNotify, 0, ft_stop_game, game);
	mlx_key_hook(game->mlx->win->ptr, ft_key_switch, game);
	game->state = GAME_START;
}
