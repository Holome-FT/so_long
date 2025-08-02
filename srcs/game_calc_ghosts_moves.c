/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_calc_ghosts_moves.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:54:25 by raamayri          #+#    #+#             */
/*   Updated: 2025/08/02 19:19:53 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/global.h"

static void	ft_calc_ghost_apply_move_and_tp(t_game *game, t_ghost *ghost,
	long long new_xy[4], int cur_dir[4])
{
	long long	tblr[4];

	tblr[0] = new_xy[1] / 16;
	tblr[1] = (new_xy[1] + 15) / 16;
	tblr[2] = new_xy[0] / 16;
	tblr[3] = (new_xy[0] + 15) / 16;
	if (ft_isvalid_move(game->map, tblr))
	{
		ghost->xy[0] = new_xy[0];
		ghost->xy[1] = new_xy[1];
		if (cur_dir[ghost->type] == 1 && \
			ghost->xy[0] <= -32)
			ghost->xy[0] = game->map->wh[0] * 16 + 16;
		else if (cur_dir[ghost->type] == 2 && \
			ghost->xy[0] >= game->map->wh[0] * 16 + 16)
			ghost->xy[0] = -32;
		else if (cur_dir[ghost->type] == 0 && \
			ghost->xy[1] <= -32)
			ghost->xy[1] = game->map->wh[1] * 16 + 16;
		else if (cur_dir[ghost->type] == 3 && \
			ghost->xy[1] >= game->map->wh[1] * 16 + 16)
			ghost->xy[1] = -32;
	}
}

static void	ft_calc_ghost_update_move(t_ghost *ghost,
	long long new_xy[4], int cur_dir[4])
{
	new_xy[0] = ghost->xy[0];
	new_xy[1] = ghost->xy[1];
	if (cur_dir[ghost->type] == 1)
		new_xy[0] -= ghost->speed;
	else if (cur_dir[ghost->type] == 2)
		new_xy[0] += ghost->speed;
	if (cur_dir[ghost->type] == 0)
		new_xy[1] -= ghost->speed;
	else if (cur_dir[ghost->type] == 3)
		new_xy[1] += ghost->speed;
}

static void	ft_switch_calc_ghosts(t_game *game, t_ghost *ghost,
	long long new_xy[4])
{
	t_map	*map;

	map = game->map;
	if (ghost->type == GHOST_BLINKY)
		ft_calc_blinky_move(map, ghost, new_xy);
	else if (ghost->type == GHOST_PINKY)
		ft_calc_pinky_move(map, ghost, new_xy);
	else if (ghost->type == GHOST_INKY)
		ft_calc_inky_move(map, ghost, new_xy);
	else if (ghost->type == GHOST_CLYDE)
		ft_calc_clyde_move(map, ghost, new_xy);
}

static void	ft_calc_ghost_rotation(t_game *game, t_ghost *ghost,
	long long new_xy[4], int cur_dir[4])
{
	if (ghost->xy[0] % 16 != 0 || ghost->xy[1] % 16 != 0)
		return ;
	ft_switch_calc_ghosts(game, ghost, new_xy);
	if (new_xy[0] < 0 || new_xy[0] >= game->map->wh[0] || \
		new_xy[1] < 0 || new_xy[1] >= game->map->wh[1])
		return ;
	if (game->map->data[new_xy[1]][new_xy[0]] != '1' && \
		game->map->data[ghost->xy[1] / 16][ghost->xy[0] / 16] != 'T')
	{
		if (new_xy[0] < ghost->xy[0] / 16)
			cur_dir[ghost->type] = 1;
		else if (new_xy[0] > ghost->xy[0] / 16)
			cur_dir[ghost->type] = 2;
		else if (new_xy[1] < ghost->xy[1] / 16)
			cur_dir[ghost->type] = 0;
		else if (new_xy[1] > ghost->xy[1] / 16)
			cur_dir[ghost->type] = 3;
	}
}

void	ft_calc_ghost_move(t_game *game, t_ghost *ghost,
	long long new_xy[4])
{
	static int	cur_dir[4] = {0, 0, 0, 0};

	ft_calc_ghost_rotation(game, ghost, new_xy, cur_dir);
	ft_calc_ghost_update_move(ghost, new_xy, cur_dir);
	ft_calc_ghost_apply_move_and_tp(game, ghost, new_xy, cur_dir);
}
