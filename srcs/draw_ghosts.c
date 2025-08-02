/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ghosts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:41:42 by raamayri          #+#    #+#             */
/*   Updated: 2025/07/30 20:51:25 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/global.h"

static void	ft_draw_ghosts_sprites(t_ghost *ghost, int sprite[2])
{
	const unsigned int	sprites = 2;
	const unsigned int	frame_rate = 8;
	static unsigned int	frame[4] = {0, 0, 0, 0};

	if (ghost->state == GHOST_SCARED)
		sprite[0] = 32 * 4;
	else if (ghost->state == GHOST_DEAD)
		sprite[0] = 32 * 5;
	else if (ghost->type == GHOST_BLINKY)
		sprite[0] = 32 * 0;
	else if (ghost->type == GHOST_PINKY)
		sprite[0] = 32 * 1;
	else if (ghost->type == GHOST_INKY)
		sprite[0] = 32 * 2;
	else if (ghost->type == GHOST_CLYDE)
		sprite[0] = 32 * 3;
	sprite[1] = (frame[ghost->type] / frame_rate) * 32;
	frame[ghost->type] = (frame[ghost->type] + 1) % (frame_rate * sprites);
}

void	ft_draw_ghosts(t_game *game)
{
	t_ghost	*cr_ghost;
	int		sprite[2];

	cr_ghost = game->map->ghosts;
	while (cr_ghost)
	{
		ft_draw_ghosts_sprites(cr_ghost, sprite);
		ft_draw_asset_into_buffer(
			game->mlx->buffer,
			(int [2]){cr_ghost->xy[0] - 8, cr_ghost->xy[1] - 8},
			game->mlx->assets->ghosts,
			(int [4]){sprite[0], sprite[1], 32, 32});
		cr_ghost = cr_ghost->next;
	}
}
