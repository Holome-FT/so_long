/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:03:41 by raamayri          #+#    #+#             */
/*   Updated: 2025/07/16 17:44:32 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/global.h"

void	ft_game_error(int id, const char *msg, t_game *game)
{
	int	fd;

	fd = STDERR_FILENO;
	if (errno == 0 && id != 0)
		errno = id;
	ft_dprintf(fd, "┌ Error %d: %s\n", errno, strerror(errno));
	if (id < 10)
		ft_dprintf(fd, "└───────── %s\n", msg);
	else if (id < 100)
		ft_dprintf(fd, "└────────── %s\n", msg);
	else
		ft_dprintf(fd, "└─────────── %s\n", msg);
	ft_exit_game(game);
}

static t_game	*ft_init_game(t_mlx *mlx, t_map **maps, t_flags *flags)
{
	t_game	*game;

	if (!mlx)
		return (NULL);
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (NULL);
	game->mlx = mlx;
	game->maps = maps;
	game->map = *maps;
	game->flags = flags;
	game->state = GAME_ONGOING;
	game->lives = 3;
	game->score = 0;
	game->moves = 1;
	return (game);
}

static int	ft_updt_game(t_game *game)
{
	if (game->map->players->state == PLAYER_DEAD && game->lives > 0)
		return (ft_reset_map(game, false), (game->state = GAME_START), 0);
	if (game->state == GAME_START)
		game->state = GAME_ONGOING;
	else if (game->state == GAME_WIN || game->state == GAME_LOSE)
	{
		ft_close_win(game, 2);
		if (game->score < INT_MAX - game->map->players->score)
			game->score += game->map->players->score;
		else
			game->score = INT_MAX;
		if (!game->flags->loop || game->state == GAME_LOSE)
			ft_game_over(game);
		else
		{
			ft_reset_map(game, true);
			game->map = game->map->next;
			if (!game->map)
				game->map = *game->maps;
			ft_open_win(game);
		}
	}
	else if (game->state == GAME_EXIT)
		ft_exit_game(game);
	return (0);
}

static int	ft_game_loop(void *param)
{
	t_game			*game;
	struct timeval	new_time;
	long long		time_us[2];

	game = (t_game *)param;
	gettimeofday(&new_time, NULL);
	time_us[0] = new_time.tv_sec * 1000000 + new_time.tv_usec;
	time_us[1] = game->old_time.tv_sec * 1000000 + game->old_time.tv_usec;
	if ((time_us[0] - time_us[1]) < (1000000 / 30))
		return (usleep((1000000 / 30) - (time_us[0] - time_us[1])), 0);
	ft_updt_game(game);
	if (game->state == GAME_START)
		game->state = GAME_WAIT_1;
	else if (game->state == GAME_WAIT_1)
	{
		game->state = GAME_ONGOING;
		return (sleep(2), gettimeofday(&game->old_time, NULL), 0);
	}
	else if (game->state == GAME_ONGOING && \
		game->map->players->state != PLAYER_DYING && \
		game->map->players->state != PLAYER_DEAD)
		ft_calc_game(game);
	if (game->state != GAME_WAIT_2)
		ft_draw_game(game, 0);
	return (gettimeofday(&game->old_time, NULL), 0);
}

void	ft_load_game(t_map **maps, t_flags *flags)
{
	t_game	*game;

	game = ft_init_game(ft_init_mlx(), maps, flags);
	if (!game)
	{
		ft_free_maps(maps);
		ft_error(EAGAIN, "Game failed to launch.");
	}
	ft_open_win(game);
	ft_draw_game(game, 2);
	game->state = GAME_ONGOING;
	gettimeofday(&game->old_time, NULL);
	srand(game->old_time.tv_sec + game->old_time.tv_usec);
	mlx_loop_hook(game->mlx->ptr, ft_game_loop, game);
	mlx_loop(game->mlx->ptr);
}
