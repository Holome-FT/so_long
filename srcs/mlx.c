/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:35:05 by raamayri          #+#    #+#             */
/*   Updated: 2025/07/29 16:35:42 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/global.h"

static void	ft_abort_game(t_mlx *mlx)
{
	if (mlx && mlx->buffer)
		free(mlx->buffer);
	if (mlx && mlx->assets)
		ft_free_assets(mlx, mlx->assets);
	if (mlx && mlx->win)
		free(mlx->win);
	if (mlx && mlx->ptr)
	{
		mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
	}
	if (mlx)
		free(mlx);
}

static int	ft_init_mobs(t_mlx *mlx)
{
	t_assets	*asts;

	asts = mlx->assets;
	asts->pacman = ft_calloc(1, sizeof(t_img));
	asts->pacman_dead = ft_calloc(1, sizeof(t_img));
	asts->ghosts = ft_calloc(1, sizeof(t_img));
	if (!asts->pacman || !asts->pacman_dead || !asts->ghosts)
		return (-1);
	if (ft_load_ast(mlx, asts->pacman, "imgs/pacman.xpm") == -1 || \
		ft_load_ast(mlx, asts->pacman_dead, "imgs/pacman_dead.xpm") == -1 || \
		ft_load_ast(mlx, asts->ghosts, "imgs/ghosts.xpm") == -1)
		return (-1);
	return (0);
}

static int	ft_init_layout(t_mlx *mlx)
{
	t_assets	*ast;

	ast = mlx->assets;
	ast->pellets = ft_calloc(1, sizeof(t_img));
	ast->walls = ft_calloc(1, sizeof(t_img));
	ast->exit = ft_calloc(1, sizeof(t_img));
	if (!ast->pellets || !ast->walls || !ast->exit)
		return (-1);
	if (ft_load_ast(mlx, ast->pellets, "imgs/pellets.xpm") == -1 || \
		ft_load_ast(mlx, ast->walls, "imgs/walls.xpm") == -1 || \
		ft_load_ast(mlx, ast->exit, "imgs/exit.xpm") == -1)
		return (-1);
	return (0);
}

t_mlx	*ft_init_mlx(void)
{
	t_mlx	*mlx;

	mlx = ft_calloc(1, sizeof(t_mlx));
	if (!mlx)
		return (NULL);
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
		return (ft_abort_game(mlx), NULL);
	mlx->win = ft_calloc(1, sizeof(t_window));
	if (!mlx->win)
		return (ft_abort_game(mlx), NULL);
	mlx->win->ptr = NULL;
	mlx->assets = ft_calloc(1, sizeof(t_assets));
	if (!mlx->assets)
		return (ft_abort_game(mlx), NULL);
	if (ft_init_mobs(mlx) == -1 || \
		ft_init_layout(mlx) == -1)
		return (ft_abort_game(mlx), NULL);
	mlx->buffer = ft_calloc(1, sizeof(t_asset));
	if (!mlx->buffer)
		return (ft_abort_game(mlx), NULL);
	return (mlx);
}
