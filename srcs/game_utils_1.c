/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:43:21 by raamayri          #+#    #+#             */
/*   Updated: 2025/08/01 19:47:35 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/global.h"

int	ft_stop_game(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	game->state = GAME_EXIT;
	return (0);
}

void	ft_close_win(t_game *game, int sleep_time)
{
	if (sleep_time > 0)
		sleep(sleep_time);
	if (game->mlx->win->ptr)
	{
		mlx_destroy_window(game->mlx->ptr, game->mlx->win->ptr);
		game->mlx->win->ptr = NULL;
	}
	if (game->mlx->buffer->ptr)
	{
		mlx_destroy_image(game->mlx->ptr, game->mlx->buffer->ptr);
		game->mlx->buffer->ptr = NULL;
	}
}

static void	ft_free_asset(t_mlx *mlx, t_asset *ast)
{
	if (!ast)
		return ;
	if (ast->ptr)
		mlx_destroy_image(mlx->ptr, ast->ptr);
	free(ast);
}

void	ft_free_assets(t_mlx *mlx, t_assets *asts)
{
	ft_free_asset(mlx, asts->pacman);
	ft_free_asset(mlx, asts->pacman_dead);
	ft_free_asset(mlx, asts->ghosts);
	ft_free_asset(mlx, asts->pellets);
	ft_free_asset(mlx, asts->walls);
	ft_free_asset(mlx, asts->exit);
	free(asts);
}

void	ft_exit_game(t_game *game)
{
	ft_close_win(game, 0);
	free(game->mlx->win);
	free(game->mlx->buffer);
	ft_free_assets(game->mlx, game->mlx->assets);
	mlx_destroy_display(game->mlx->ptr);
	free(game->mlx->ptr);
	free(game->mlx);
	ft_free_maps(game->maps);
	free(game);
	exit(EXIT_SUCCESS);
}
