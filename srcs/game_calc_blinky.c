/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_calc_blinky.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 22:38:03 by raamayri          #+#    #+#             */
/*   Updated: 2025/08/01 20:02:19 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/global.h"

static void	ft_calc_blinky_trg(long long trg_xy[2], t_map *map, t_ghost *ghost)
{
	if (ghost->state == GHOST_DEFAULT)
	{
		trg_xy[0] = map->players->xy[0] / 16;
		trg_xy[1] = map->players->xy[1] / 16;
	}
	else if (ghost->state == GHOST_SCATTER)
	{
		trg_xy[0] = map->wh[0] - 1;
		trg_xy[1] = 0;
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

void	ft_calc_blinky_move(t_map *map, t_ghost *ghost,
	long long new_xy[4])
{
	long long	trg_xy[2];

	trg_xy[0] = new_xy[0];
	trg_xy[1] = new_xy[1];
	ft_calc_blinky_trg(trg_xy, map, ghost);
	ft_bfs(map, new_xy, trg_xy);
}
