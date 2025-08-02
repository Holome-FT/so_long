/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:59:05 by raamayri          #+#    #+#             */
/*   Updated: 2025/07/29 21:33:41 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/global.h"

void	ft_draw_game_over(t_game *game)
{
	char	txt[128];

	mlx_string_put(game->mlx->ptr, game->mlx->win->ptr,
		16, 32 + 8 * 0 + 16 * 0, 0xFFFFFFFF, "GAME OVER");
	ft_sprintf(txt, "MOVES: %d", game->moves);
	mlx_string_put(game->mlx->ptr, game->mlx->win->ptr,
		16, 32 + 8 * 1 + 16 * 1, 0xFFFFFFFF, txt);
	ft_sprintf(txt, "SCORE: %d", game->score);
	mlx_string_put(game->mlx->ptr, game->mlx->win->ptr,
		16, 32 + 8 * 2 + 16 * 2, 0xFFFFFFFF, txt);
	mlx_string_put(game->mlx->ptr, game->mlx->win->ptr,
		16, 32 + 8 * 3 + 16 * 3, 0xFFFFFFFF, "Press Enter to exit");
}

static int	ft_key_switch(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == XK_Escape)
		ft_stop_game(param);
	if (keycode == XK_Return)
		game->state = GAME_EXIT;
	return (0);
}

static void	ft_make_win(t_game	*game)
{
	game->mlx->win->ptr = mlx_new_window(
			game->mlx->ptr,
			game->mlx->win->wh[0],
			game->mlx->win->wh[1],
			"Pacman - Game Over");
	if (!game->mlx->win->ptr)
		ft_exit_game(game);
	game->mlx->buffer->ptr = mlx_new_image(
			game->mlx->ptr,
			game->mlx->win->wh[0],
			game->mlx->win->wh[1]);
	if (!game->mlx->buffer->ptr)
		ft_exit_game(game);
	game->mlx->buffer->pda = mlx_get_data_addr(
			game->mlx->buffer->ptr,
			&game->mlx->buffer->bpp,
			&game->mlx->buffer->bpl,
			&game->mlx->buffer->eda);
	if (!game->mlx->buffer->pda)
		ft_exit_game(game);
}

void	ft_game_over(t_game *game)
{
	game->mlx->win->wh[0] = 512;
	game->mlx->win->wh[1] = 256;
	game->mlx->buffer->wh[0] = 1;
	game->mlx->buffer->wh[1] = 1;
	ft_make_win(game);
	ft_draw_game_over(game);
	mlx_hook(game->mlx->win->ptr, DestroyNotify, 0, ft_stop_game, game);
	mlx_key_hook(game->mlx->win->ptr, ft_key_switch, game);
	game->state = GAME_WAIT_2;
}
