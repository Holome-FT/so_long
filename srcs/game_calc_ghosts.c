/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_calc_ghosts.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:54:25 by raamayri          #+#    #+#             */
/*   Updated: 2025/08/02 18:41:09 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/global.h"

static void	ft_calc_ghost_slay(t_game *game, t_ghost *ghost, t_player *player)
{
	const int	offset = 8;

	if (ghost->xy[0] < player->xy[0] + offset && \
		ghost->xy[0] + offset > player->xy[0] && \
		ghost->xy[1] < player->xy[1] + offset && \
		ghost->xy[1] + offset > player->xy[1])
	{
		if (player->state == PLAYER_DEFAULT && \
			(ghost->state == GHOST_DEFAULT || ghost->state == GHOST_SCATTER))
			ft_kill_pacman(game);
		if (player->state == PLAYER_POWERED && ghost->state == GHOST_SCARED)
		{
			ghost->state = GHOST_DEAD;
			if (player->score > INT_MAX - 200)
				player->score = INT_MAX;
			else
				player->score += 200;
		}
	}
}

static void	ft_calc_ghosts_scatter(t_ghost *ghosts, t_player *player,
	long long nb_pellets)
{
	const unsigned int	to_frame = 360 + 120;
	static unsigned int	frame = 0;
	t_ghost				*cr_ghost;

	cr_ghost = ghosts;
	while (cr_ghost)
	{
		if (cr_ghost->state == GHOST_SCATTER && frame >= 120)
			cr_ghost->state = GHOST_DEFAULT;
		else if (cr_ghost->state == GHOST_DEFAULT && \
			!(cr_ghost->type == GHOST_BLINKY && nb_pellets >= 80))
			cr_ghost->state = GHOST_SCATTER;
		cr_ghost = cr_ghost->next;
	}
	frame = (frame + 1) % to_frame;
	if (player->state == PLAYER_DYING || player->state == PLAYER_DEAD)
		frame = 0;
}

static void	ft_calc_ghosts_dead(t_ghost *ghost)
{
	const unsigned int	to_frame = 120;
	static unsigned int	frame[4] = {0, 0, 0, 0};

	if (ghost->state != GHOST_DEAD)
		return ;
	frame[ghost->type] = (frame[ghost->type] + 1) % to_frame;
	if (frame[ghost->type] == 0)
		ghost->state = GHOST_DEFAULT;
}

void	ft_calc_ghosts(t_game *game, long long nb_pellets)
{
	t_ghost		*ghost;
	t_player	*player;
	long long	new_xy[4];

	ghost = game->map->ghosts;
	player = game->map->players;
	while (ghost)
	{
		if (ghost->speed != player->speed)
		{
			ghost->xy[0] = ghost->xy[0] / 16 * 16;
			ghost->xy[1] = ghost->xy[1] / 16 * 16;
			ghost->speed = player->speed;
		}
		ft_calc_ghosts_dead(ghost);
		new_xy[0] = ghost->xy[0] / 16;
		new_xy[1] = ghost->xy[1] / 16;
		new_xy[2] = ghost->xy[0] / 16;
		new_xy[3] = ghost->xy[1] / 16;
		ft_calc_ghost_move(game, ghost, new_xy);
		ft_calc_ghost_slay(game, ghost, player);
		ghost = ghost->next;
	}
	ft_calc_ghosts_scatter(game->map->ghosts, player, nb_pellets);
}
