/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_other.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:39:32 by raamayri          #+#    #+#             */
/*   Updated: 2025/08/01 17:44:37 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/global.h"

size_t	ft_draw_pellets(t_game *game)
{
	t_pellet	*cr_pellet;
	size_t		count;

	count = 0;
	cr_pellet = game->map->pellets;
	while (cr_pellet)
	{
		if (cr_pellet->state == PELLET_DEAD)
		{
			cr_pellet = cr_pellet->next;
			continue ;
		}
		else if (cr_pellet->state == PELLET_DEFAULT)
			ft_draw_asset_into_buffer(game->mlx->buffer,
				(int [2]){cr_pellet->xy[0], cr_pellet->xy[1]},
				game->mlx->assets->pellets, (int [4]){0, 0, 16, 16});
		else if (cr_pellet->state == PELLET_POWERED)
			ft_draw_asset_into_buffer(game->mlx->buffer,
				(int [2]){cr_pellet->xy[0], cr_pellet->xy[1]},
				game->mlx->assets->pellets, (int [4]){0, 16, 16, 16});
		count++;
		cr_pellet = cr_pellet->next;
	}
	return (count);
}

static void	ft_draw_exit_sprite(t_game *game, int sprite[2])
{
	const unsigned int	sprites = 4;
	const unsigned int	frame_rate = 8;
	static unsigned int	frame = 0;

	(void)game;
	sprite[0] = 0;
	sprite[1] = (frame / frame_rate) * 16;
	frame = (frame + 1) % (frame_rate * sprites);
}

void	ft_draw_exit(t_game *game)
{
	int	i[2];
	int	sprite[2];

	i[0] = 0;
	while (i[0] < (int)game->map->wh[1])
	{
		i[1] = 0;
		while (i[1] < (int)game->map->wh[0])
		{
			if (ft_strchr("E", game->map->data[i[0]][i[1]]))
			{
				ft_draw_exit_sprite(game, sprite);
				ft_draw_asset_into_buffer(
					game->mlx->buffer,
					(int [2]){i[1] * 16, i[0] * 16},
					game->mlx->assets->exit,
					(int [4]){sprite[0], sprite[1], 16, 16});
			}
			i[1]++;
		}
		i[0]++;
	}
}

void	ft_draw_info(t_game *game)
{
	char	txt[128];

	ft_sprintf(txt, "LIVES: %d", game->lives);
	mlx_string_put(game->mlx->ptr, game->mlx->win->ptr,
		16, 32 + 8 * 0 + 16 * 0, 0xFFFFFFFF, txt);
	ft_sprintf(txt, "MOVES: %d", game->moves);
	mlx_string_put(game->mlx->ptr, game->mlx->win->ptr,
		16, 32 + 8 * 1 + 16 * 1, 0xFFFFFFFF, txt);
	ft_sprintf(txt, "SCORE: %d (+%d)", game->score, game->map->players->score);
	mlx_string_put(game->mlx->ptr, game->mlx->win->ptr,
		16, 32 + 8 * 2 + 16 * 2, 0xFFFFFFFF, txt);
}
