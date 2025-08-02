/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_calc_inky.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 22:36:44 by raamayri          #+#    #+#             */
/*   Updated: 2025/08/01 20:02:32 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/global.h"

// NOTE: Pinky & Inky Up Bug (for V2)
// When Pac-Man Up, Pinky & Inky target 4 tiles up and 4 tiles left.
static void	ft_clc_inky_default_target(long long trg_xy[2], t_map *map)
{
	t_player	*player;
	t_ghost		*blinky;

	player = map->players;
	blinky = map->ghosts;
	trg_xy[0] = player->xy[0] / 16;
	trg_xy[1] = player->xy[1] / 16;
	if (player->dirct[0] == PLAYER_LEFT)
		trg_xy[0] -= 2;
	else if (player->dirct[0] == PLAYER_RIGHT)
		trg_xy[0] += 2;
	else if (player->dirct[0] == PLAYER_UP)
		trg_xy[1] -= 2;
	else if (player->dirct[0] == PLAYER_DOWN)
		trg_xy[1] += 2;
	trg_xy[0] *= 2;
	trg_xy[1] *= 2;
	trg_xy[0] -= (blinky->xy[0] / 16);
	trg_xy[1] -= (blinky->xy[1] / 16);
}

static void	ft_calc_inky_trg(long long trg_xy[2], t_map *map, t_ghost *ghost)
{
	if (ghost->state == GHOST_DEFAULT)
		ft_clc_inky_default_target(trg_xy, map);
	else if (ghost->state == GHOST_SCATTER)
	{
		trg_xy[0] = map->wh[0] - 1;
		trg_xy[1] = map->wh[1] - 1;
	}
	else if (ghost->state == GHOST_SCARED)
	{
		trg_xy[0] = rand() % map->wh[0];
		trg_xy[1] = rand() % map->wh[1];
	}
	else if (ghost->state == GHOST_DEAD)
	{
		trg_xy[0] = map->wh[0] / 2;
		trg_xy[1] = map->wh[1] / 2;
	}
}

void	ft_calc_inky_move(t_map *map, t_ghost *ghost,
	long long new_xy[4])
{
	long long	trg_xy[2];

	trg_xy[0] = new_xy[0];
	trg_xy[1] = new_xy[1];
	ft_calc_inky_trg(trg_xy, map, ghost);
	ft_bfs(map, new_xy, trg_xy);
}
