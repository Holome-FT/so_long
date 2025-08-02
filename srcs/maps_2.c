/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:06:03 by raamayri          #+#    #+#             */
/*   Updated: 2025/07/16 17:08:18 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/global.h"

static int	ft_add_pellet(t_map *map, t_pellet **pellets, char type)
{
	t_pellet	*cp_pellets;
	t_pellet	*pellet;

	pellet = ft_calloc(1, sizeof(t_pellet));
	if (!pellet)
		return (-1);
	pellet->s_state = PELLET_DEFAULT;
	pellet->state = PELLET_DEFAULT;
	if (type == 'B')
	{
		pellet->s_state = PELLET_POWERED;
		pellet->state = PELLET_POWERED;
	}
	pellet->xy[0] = map->wh[0] * 16;
	pellet->xy[1] = map->wh[1] * 16;
	pellet->next = NULL;
	cp_pellets = *pellets;
	if (!cp_pellets)
		return ((*pellets = pellet), (pellet->prev = NULL), 0);
	while (cp_pellets->next)
		cp_pellets = cp_pellets->next;
	return ((cp_pellets->next = pellet), (pellet->prev = cp_pellets), 0);
}

static int	ft_add_ghost(t_map *map, t_ghost **ghosts)
{
	t_ghost	*cp_ghosts;
	t_ghost	*ghost;
	size_t	i;

	ghost = ft_calloc(1, sizeof(t_ghost));
	if (!ghost)
		return (-1);
	ghost->state = GHOST_DEFAULT;
	ghost->type = GHOST_BLINKY;
	ghost->s_xy[0] = map->wh[0] * 16;
	ghost->s_xy[1] = map->wh[1] * 16;
	ghost->xy[0] = map->wh[0] * 16;
	ghost->xy[1] = map->wh[1] * 16;
	ghost->speed = 2;
	ghost->next = NULL;
	cp_ghosts = *ghosts;
	if (!cp_ghosts)
		return ((*ghosts = ghost), (ghost->prev = NULL), 0);
	i = 1;
	while (cp_ghosts->next && ++i > 0)
		cp_ghosts = cp_ghosts->next;
	ghost->type = i % 4;
	return ((cp_ghosts->next = ghost), (ghost->prev = cp_ghosts), 0);
}

static int	ft_add_player(t_map *map, t_player **players)
{
	t_player	*cp_players;
	t_player	*player;

	player = ft_calloc(1, sizeof(t_player));
	if (!player)
		return (-1);
	player->state = PLAYER_DEFAULT;
	player->dirct[0] = PLAYER_LEFT;
	player->dirct[1] = PLAYER_LEFT;
	player->s_xy[0] = map->wh[0] * 16;
	player->s_xy[1] = map->wh[1] * 16;
	player->xy[0] = map->wh[0] * 16;
	player->xy[1] = map->wh[1] * 16;
	player->speed = 2;
	player->score = 0;
	player->next = NULL;
	cp_players = *players;
	if (!cp_players)
		return ((*players = player), (player->prev = NULL), 0);
	while (cp_players->next)
		cp_players = cp_players->next;
	return ((cp_players->next = player), (player->prev = cp_players), 0);
}

int	ft_init_map(t_map *map)
{
	map->wh[1] = 0;
	while (map->data[map->wh[1]])
	{
		map->wh[0] = 0;
		while (map->data[map->wh[1]][map->wh[0]])
		{
			if (ft_strchr("P", map->data[map->wh[1]][map->wh[0]]))
				if (ft_add_player(map, &map->players) == -1)
					return (ft_free_array((void ***)&map->data), -1);
			if (ft_strchr("M", map->data[map->wh[1]][map->wh[0]]))
				if (ft_add_ghost(map, &map->ghosts) == -1)
					return (ft_free_array((void ***)&map->data), -1);
			if (ft_strchr("C", map->data[map->wh[1]][map->wh[0]]))
				if (ft_add_pellet(map, &map->pellets, 'C') == -1)
					return (ft_free_array((void ***)&map->data), -1);
			if (ft_strchr("B", map->data[map->wh[1]][map->wh[0]]))
				if (ft_add_pellet(map, &map->pellets, 'B') == -1)
					return (ft_free_array((void ***)&map->data), -1);
			map->wh[0]++;
		}
		map->wh[1]++;
	}
	return (0);
}
