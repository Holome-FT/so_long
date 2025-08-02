/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:38:33 by raamayri          #+#    #+#             */
/*   Updated: 2025/07/29 16:40:05 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/global.h"

static void	ft_draw_walls_sprite(char mtx[3][3], int wall_params[4])
{
	wall_params[0] = 0;
	wall_params[1] = 0;
	if (ft_strncmp(mtx[0], "111", 3) == 0 && \
		ft_strncmp(mtx[1], "111", 3) == 0 && \
		ft_strncmp(mtx[2], "111", 3) == 0)
	{
		wall_params[0] = 16;
		wall_params[1] = 16;
	}
	else if (ft_memcmp(&mtx[0][1], "1", 1) == 0 && \
		ft_memcmp(&mtx[2][1], "1", 1) == 0 && \
		(ft_memcmp(mtx[1], "01", 2) == 0 || \
		ft_memcmp(&mtx[1][1], "10", 2) == 0))
	{
		wall_params[0] = 0;
		wall_params[1] = 16;
	}
	else if (ft_memcmp(mtx[1], "111", 3) == 0 && \
		(ft_memcmp(&mtx[0][1], "0", 1) == 0 || \
		ft_memcmp(&mtx[2][1], "0", 1) == 0))
	{
		wall_params[0] = 16;
		wall_params[1] = 0;
	}
}

static void	ft_draw_walls_mtx(t_game *game, int xy[2], char mtx[3][3])
{
	t_map	*map;
	int		i[2];

	map = game->map;
	i[0] = -1;
	while (i[0] <= 1)
	{
		i[1] = -1;
		while (i[1] <= 1)
		{
			mtx[i[0] + 1][i[1] + 1] = '1';
			if (xy[1] + i[0] >= 0 && \
				xy[1] + i[0] < (int)map->wh[1] && \
				xy[0] + i[1] >= 0 && \
				xy[0] + i[1] < (int)map->wh[0] && \
				!ft_strchr("1", map->data[xy[1] + i[0]][xy[0] + i[1]]))
				mtx[i[0] + 1][i[1] + 1] = '0';
			i[1]++;
		}
		i[0]++;
	}
}

void	ft_draw_walls(t_game *game)
{
	char	mtx[3][3];
	int		wall_params[4];
	int		i[2];

	i[0] = 0;
	while (i[0] < (int)game->map->wh[1])
	{
		i[1] = 0;
		while (i[1] < (int)game->map->wh[0])
		{
			ft_draw_walls_mtx(game, (int [2]){i[1], i[0]}, mtx);
			ft_draw_walls_sprite(mtx, wall_params);
			wall_params[2] = 16;
			wall_params[3] = 16;
			if (ft_strchr("1", game->map->data[i[0]][i[1]]))
				ft_draw_asset_into_buffer(
					game->mlx->buffer,
					(int [2]){i[1] * 16, i[0] * 16},
					game->mlx->assets->walls,
					wall_params);
			i[1]++;
		}
		i[0]++;
	}
}
