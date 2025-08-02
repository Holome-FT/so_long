/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pacman.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:41:06 by raamayri          #+#    #+#             */
/*   Updated: 2025/07/30 20:56:33 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/global.h"

static void	ft_draw_pacman_dead_sprite(t_player *player, int sprite[2])
{
	const unsigned int	sprites = 10;
	const unsigned int	frame_rate = 6;
	static unsigned int	frame = 0;

	sprite[0] = 0;
	sprite[1] = (frame / frame_rate) * 32;
	frame = (frame + 1) % (frame_rate * sprites);
	if (frame == 0)
		player->state = PLAYER_DEAD;
}

static void	ft_draw_pacman_sprite(t_player *player, int sprite[2])
{
	const unsigned int	sprites = 4;
	const unsigned int	frame_rate = 2;
	static unsigned int	frame = 0;

	if (player->dirct[0] == PLAYER_RIGHT)
		sprite[0] = 32 * 0;
	else if (player->dirct[0] == PLAYER_LEFT)
		sprite[0] = 32 * 1;
	else if (player->dirct[0] == PLAYER_UP)
		sprite[0] = 32 * 2;
	else if (player->dirct[0] == PLAYER_DOWN)
		sprite[0] = 32 * 3;
	sprite[1] = (frame / frame_rate) * 32;
	frame = (frame + 1) % (frame_rate * sprites);
}

void	ft_draw_pacman(t_game *game)
{
	t_player	*player;
	int			sprite[2];

	player = game->map->players;
	if (player->state == PLAYER_DEFAULT || \
		player->state == PLAYER_POWERED)
	{
		ft_draw_pacman_sprite(player, sprite);
		ft_draw_asset_into_buffer(
			game->mlx->buffer,
			(int [2]){player->xy[0] - 8, player->xy[1] - 8},
			game->mlx->assets->pacman,
			(int [4]){sprite[0], sprite[1], 32, 32});
	}
	else if (player->state == PLAYER_DYING)
	{
		ft_draw_pacman_dead_sprite(player, sprite);
		ft_draw_asset_into_buffer(
			game->mlx->buffer,
			(int [2]){player->xy[0] - 8, player->xy[1] - 8},
			game->mlx->assets->pacman_dead,
			(int [4]){sprite[0], sprite[1], 32, 32});
		if (player->state == PLAYER_DEAD && game->lives == 0)
			game->state = GAME_LOSE;
	}
}
