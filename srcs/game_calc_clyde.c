/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_calc_clyde.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 22:35:53 by raamayri          #+#    #+#             */
/*   Updated: 2025/08/01 20:04:43 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/global.h"

static void	ft_calc_clyde_default_target(long long trg_xy[2], t_map *map)
{
	t_player	*player;

	player = map->players;
	trg_xy[0] -= (player->xy[0] / 16);
	trg_xy[1] -= (player->xy[1] / 16);
	trg_xy[0] *= trg_xy[0];
	trg_xy[1] *= trg_xy[1];
	if (trg_xy[0] + trg_xy[1] > 8 * 8)
	{
		trg_xy[0] = player->xy[0] / 16;
		trg_xy[1] = player->xy[1] / 16;
	}
	else
	{
		trg_xy[0] = 0;
		trg_xy[1] = map->wh[1] - 1;
	}
}

static void	ft_calc_clyde_trg(long long trg_xy[2], t_map *map, t_ghost *ghost)
{
	if (ghost->state == GHOST_DEFAULT)
		ft_calc_clyde_default_target(trg_xy, map);
	else if (ghost->state == GHOST_SCATTER)
	{
		trg_xy[0] = 0;
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

void	ft_calc_clyde_move(t_map *map, t_ghost *ghost,
	long long new_xy[4])
{
	long long	trg_xy[2];

	trg_xy[0] = new_xy[0];
	trg_xy[1] = new_xy[1];
	ft_calc_clyde_trg(trg_xy, map, ghost);
	ft_bfs(map, new_xy, trg_xy);
}
