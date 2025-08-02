/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:02:12 by raamayri          #+#    #+#             */
/*   Updated: 2025/08/02 21:06:20 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/global.h"

void	ft_debug_key_switch_1(int keycode, t_game *game)
{
	t_pellet	*cr_pellet;

	if (keycode == XK_F1)
	{
		game->map->players->xy[0] = game->map->players->s_xy[0];
		game->map->players->xy[1] = game->map->players->s_xy[1];
		ft_dprintf(STDOUT_FILENO, "[DEBUG]\tPacman goes to spawn\n");
	}
	else if (keycode == XK_F2)
	{
		cr_pellet = game->map->pellets;
		while (cr_pellet)
		{
			cr_pellet->state = PELLET_DEAD;
			cr_pellet = cr_pellet->next;
		}
		game->map->players->xy[0] = game->map->players->xy[0] / 16 * 16;
		game->map->players->xy[1] = game->map->players->xy[1] / 16 * 16;
		ft_dprintf(STDOUT_FILENO, "[DEBUG]\tPacman eats all pellets\n");
	}
}

void	ft_debug_key_switch_2(int keycode, t_game *game)
{
	t_ghost	*cr_ghost;

	if (keycode == XK_F3)
	{
		game->score = INT_MAX;
		game->map->players->score = INT_MAX;
		game->moves = INT_MAX;
		ft_dprintf(STDOUT_FILENO, "[DEBUG]\tPacman's stats maxed out\n");
	}
	else if (keycode == XK_F4)
	{
		ft_kill_pacman(game);
		ft_dprintf(STDOUT_FILENO, "[DEBUG]\tPacman was killed\n");
	}
	else if (keycode == XK_F5)
	{
		cr_ghost = game->map->ghosts;
		while (cr_ghost)
		{
			cr_ghost->state = GHOST_DEAD;
			cr_ghost = cr_ghost->next;
		}
		ft_dprintf(STDOUT_FILENO, "[DEBUG]\tPacman kills all ghosts\n");
	}
}
