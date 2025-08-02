/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:45:54 by raamayri          #+#    #+#             */
/*   Updated: 2025/07/31 20:56:00 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/global.h"

void	ft_kill_pacman(t_game *game)
{
	if (game->map->players->state == PLAYER_DEFAULT)
	{
		game->lives--;
		game->map->players->state = PLAYER_DYING;
	}
}

static void	ft_reset_player(t_player *player, bool force)
{
	while (player)
	{
		player->state = PLAYER_DEFAULT;
		player->dirct[0] = PLAYER_LEFT;
		player->dirct[1] = PLAYER_LEFT;
		player->xy[0] = player->s_xy[0];
		player->xy[1] = player->s_xy[1];
		if (force)
		{
			player->speed = 2;
			player->score = 0;
		}
		player = player->next;
	}
}

static void	ft_reset_ghosts(t_ghost *ghost, bool force)
{
	while (ghost)
	{
		ghost->state = GHOST_DEFAULT;
		ghost->xy[0] = ghost->s_xy[0];
		ghost->xy[1] = ghost->s_xy[1];
		if (force)
		{
			ghost->speed = 2;
		}
		ghost = ghost->next;
	}
}

void	ft_reset_map(t_game *game, bool force)
{
	t_pellet	*pellet;

	ft_reset_player(game->map->players, force);
	ft_reset_ghosts(game->map->ghosts, force);
	if (force)
	{
		pellet = game->map->pellets;
		while (pellet)
		{
			pellet->state = PELLET_DEFAULT;
			if (pellet->s_state == PELLET_POWERED)
				pellet->state = PELLET_POWERED;
			pellet = pellet->next;
		}
	}
}

int	ft_calc_game(t_game *game)
{
	t_map		*map;
	t_player	*player;
	long long	plt;

	map = game->map;
	player = map->players;
	ft_calc_player(game);
	plt = ft_calc_pellets(game);
	if (plt == 100 && \
		player->xy[0] % 16 == 0 && player->xy[1] % 16 == 0 && \
		player->xy[0] / 16 > 0 && player->xy[0] / 16 < map->wh[0] - 1 && \
		player->xy[1] / 16 > 0 && player->xy[1] / 16 < map->wh[1] - 1 && \
		map->data[player->xy[1] / 16][player->xy[0] / 16] == 'E')
		return ((game->state = GAME_WIN), 0);
	else if (plt > 40)
		player->speed = 4;
	return (ft_calc_ghosts(game, plt), 0);
}
