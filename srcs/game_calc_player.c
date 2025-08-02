/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_calc_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:49:56 by raamayri          #+#    #+#             */
/*   Updated: 2025/07/31 20:40:05 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/global.h"

static bool	ft_teleport_player(t_map *map, long long xy[2])
{
	if (map->players->dirct[0] == PLAYER_LEFT && \
		xy[0] <= -32)
	{
		map->players->xy[0] = map->wh[0] * 16 + 16;
		return (true);
	}
	if (map->players->dirct[0] == PLAYER_RIGHT && \
		xy[0] >= map->wh[0] * 16 + 16)
	{
		map->players->xy[0] = -32;
		return (true);
	}
	if (map->players->dirct[0] == PLAYER_UP && \
		xy[1] <= -32)
	{
		map->players->xy[1] = map->wh[1] * 16 + 16;
		return (true);
	}
	if (map->players->dirct[0] == PLAYER_DOWN && \
		xy[1] >= map->wh[1] * 16 + 16)
	{
		map->players->xy[1] = -32;
		return (true);
	}
	return (false);
}

static void	ft_rotate_player(t_game *game, t_map *map, long long xy[2])
{
	long long	mod[2];

	mod[0] = xy[0] % 16;
	mod[1] = xy[1] % 16;
	if (mod[0] < 0)
		mod[0] += 16;
	if (mod[1] < 0)
		mod[1] += 16;
	if (map->players->dirct[0] != map->players->dirct[1] && \
		(mod[0] >= 15 || mod[0] <= 1) && \
		(mod[1] >= 15 || mod[1] <= 1) && \
		xy[0] / 16 >= 0 && xy[0] / 16 <= map->wh[0] - 1 && \
		xy[1] / 16 >= 0 && xy[1] / 16 <= map->wh[1] - 1)
	{
		map->players->dirct[0] = map->players->dirct[1];
		xy[0] = (xy[0] / 16) * 16;
		xy[1] = (xy[1] / 16) * 16;
		if (game->moves < INT_MAX)
			game->moves++;
	}
}

static void	ft_move_player(t_map *map, long long xy[2])
{
	if (map->players->dirct[0] == PLAYER_LEFT)
		xy[0] -= map->players->speed;
	else if (map->players->dirct[0] == PLAYER_RIGHT)
		xy[0] += map->players->speed;
	else if (map->players->dirct[0] == PLAYER_UP)
		xy[1] -= map->players->speed;
	else if (map->players->dirct[0] == PLAYER_DOWN)
		xy[1] += map->players->speed;
}

static void	ft_calc_player_powered(t_player *player, t_ghost *ghosts)
{
	const unsigned int	to_frame = 180;
	static unsigned int	frame = 0;
	t_ghost				*cr_ghost;

	frame = (frame + 1) % to_frame;
	if (frame == 0)
	{
		player->state = PLAYER_DEFAULT;
		cr_ghost = ghosts;
		while (cr_ghost)
		{
			if (cr_ghost->state == GHOST_SCARED)
				cr_ghost->state = GHOST_DEFAULT;
			cr_ghost = cr_ghost->next;
		}
	}
}

void	ft_calc_player(t_game *game)
{
	t_map		*map;
	t_player	*player;
	long long	new_xy[2];
	long long	tblr[4];

	map = game->map;
	player = map->players;
	new_xy[0] = player->xy[0];
	new_xy[1] = player->xy[1];
	if (player->state == PLAYER_POWERED)
		ft_calc_player_powered(player, map->ghosts);
	if (player->state == PLAYER_DYING || \
		player->state == PLAYER_DEAD || \
		ft_teleport_player(map, new_xy))
		return ;
	ft_rotate_player(game, map, new_xy);
	ft_move_player(map, new_xy);
	tblr[0] = new_xy[1] / 16;
	tblr[1] = (new_xy[1] + 15) / 16;
	tblr[2] = new_xy[0] / 16;
	tblr[3] = (new_xy[0] + 15) / 16;
	if (!ft_isvalid_move(map, tblr))
		return ;
	player->xy[0] = new_xy[0];
	player->xy[1] = new_xy[1];
}
