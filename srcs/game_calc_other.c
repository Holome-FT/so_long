/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_calc_other.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:51:51 by raamayri          #+#    #+#             */
/*   Updated: 2025/07/31 18:57:07 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/global.h"

bool	ft_isvalid_move(t_map *map, long long tblr[4])
{
	if (tblr[0] < 0)
		tblr[0] = 0;
	else if (tblr[0] >= map->wh[1])
		tblr[0] = map->wh[1] - 1;
	if (tblr[1] < 0)
		tblr[1] = 0;
	else if (tblr[1] >= map->wh[1])
		tblr[1] = map->wh[1] - 1;
	if (tblr[2] < 0)
		tblr[2] = 0;
	else if (tblr[2] >= map->wh[0])
		tblr[2] = map->wh[0] - 1;
	if (tblr[3] < 0)
		tblr[3] = 0;
	else if (tblr[3] >= map->wh[0])
		tblr[3] = map->wh[0] - 1;
	if ((map->data[tblr[0]][tblr[2]] == '1' || \
		map->data[tblr[0]][tblr[3]] == '1' || \
		map->data[tblr[1]][tblr[2]] == '1' || \
		map->data[tblr[1]][tblr[3]] == '1'))
		return (false);
	return (true);
}

void	ft_calc_ghosts_scared(t_map *map, t_ghost *ghost, long long rdm_xy[2])
{
	rdm_xy[0] = ghost->xy[0] / 16 - map->players->xy[0] / 16;
	rdm_xy[0] = ghost->xy[0] / 16 + rdm_xy[0] * 4;
	if (rdm_xy[0] < 0)
		rdm_xy[0] = 0;
	else if (rdm_xy[0] >= map->wh[0])
		rdm_xy[0] = map->wh[0] - 1;
	rdm_xy[0] *= 16;
	rdm_xy[1] = ghost->xy[1] / 16 - map->players->xy[1] / 16;
	rdm_xy[1] = ghost->xy[1] / 16 + rdm_xy[1] * 4;
	if (rdm_xy[1] < 0)
		rdm_xy[1] = 0;
	else if (rdm_xy[1] >= map->wh[1])
		rdm_xy[1] = map->wh[1] - 1;
	rdm_xy[1] *= 16;
}

void	ft_eat_pellets(t_map *map, t_pellet *pellet)
{
	t_ghost	*cr_ghost;

	cr_ghost = map->ghosts;
	if (pellet->state == PELLET_DEFAULT)
	{
		if (map->players->score < INT_MAX - 10)
			map->players->score += 10;
		else
			map->players->score = INT_MAX;
	}
	else if (pellet->state == PELLET_POWERED)
	{
		if (map->players->score < INT_MAX - 50)
			map->players->score += 50;
		else
			map->players->score = INT_MAX;
		map->players->state = PLAYER_POWERED;
		while (cr_ghost)
		{
			if (cr_ghost->state != GHOST_DEAD)
				cr_ghost->state = GHOST_SCARED;
			cr_ghost = cr_ghost->next;
		}
	}
	pellet->state = PELLET_DEAD;
}

long long	ft_calc_pellets(t_game *game)
{
	t_pellet	*cr_pellets;
	long long	nb_pellets[2];

	cr_pellets = game->map->pellets;
	nb_pellets[0] = 0;
	nb_pellets[1] = 0;
	while (cr_pellets)
	{
		if (cr_pellets->xy[0] == game->map->players->xy[0] && \
			cr_pellets->xy[1] == game->map->players->xy[1])
			ft_eat_pellets(game->map, cr_pellets);
		if (cr_pellets->state == PELLET_DEAD)
			nb_pellets[1]++;
		nb_pellets[0]++;
		cr_pellets = cr_pellets->next;
	}
	return (nb_pellets[1] * 100 / nb_pellets[0]);
}
