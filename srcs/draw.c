/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:36:23 by raamayri          #+#    #+#             */
/*   Updated: 2025/07/29 19:29:06 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/global.h"

int	ft_load_ast(t_mlx *mlx, t_asset *ast, char *ast_path)
{
	int	ast_wh[2];
	int	ast_px[3];

	ast->ptr = mlx_xpm_file_to_image(mlx->ptr, ast_path,
			&ast_wh[0], &ast_wh[1]);
	if (!ast->ptr)
		return (-1);
	ast->wh[0] = (long long)ast_wh[0];
	ast->wh[1] = (long long)ast_wh[1];
	ast->pda = mlx_get_data_addr(ast->ptr,
			&ast_px[0],
			&ast_px[1],
			&ast_px[2]);
	ast->bpp = (long long)ast_px[0];
	ast->bpl = (long long)ast_px[1];
	ast->eda = (long long)ast_px[2];
	if (!ast->pda)
		return (-1);
	return (0);
}

void	ft_put_pixel_into_buffer(t_asset *buffer, unsigned int color, int xy[2])
{
	char	*dst;

	if (xy[0] < 0 || xy[0] >= buffer->wh[0] || \
		xy[1] < 0 || xy[1] >= buffer->wh[1] || \
		color == 0xFF000000)
		return ;
	dst = buffer->pda + (xy[1] * buffer->bpl + xy[0] * (buffer->bpp / 8));
	*(unsigned int *)dst = color;
}

void	ft_draw_asset_into_buffer(t_asset *buffer, int xy[2],
						t_asset *asset, int xywh[4])
{
	char			*asset_pixel;
	unsigned int	color;
	int				i[2];

	if (!buffer || !buffer->pda || !asset || !asset->pda)
		return ;
	i[0] = 0;
	while (i[0] < xywh[3])
	{
		i[1] = 0;
		while (i[1] < xywh[2] && xywh[0] + i[1] != xywh[2] - 1)
		{
			asset_pixel = asset->pda + \
					((xywh[1] + i[0]) * asset->bpl + \
					(xywh[0] + i[1]) * (asset->bpp / 8));
			color = *(unsigned int *)asset_pixel;
			ft_put_pixel_into_buffer(buffer, color,
				(int [2]){xy[0] + i[1], xy[1] + i[0]});
			i[1]++;
		}
		i[0]++;
	}
}

void	ft_clear_buffer(t_asset *buffer)
{
	unsigned int	*buffer_pixel;
	int				i[2];

	if (!buffer || !buffer->pda)
		return ;
	buffer_pixel = (unsigned int *)buffer->pda;
	i[0] = 0;
	while (i[0] < buffer->wh[1])
	{
		i[1] = 0;
		while (i[1] < buffer->wh[0])
		{
			buffer_pixel[i[0] * buffer->wh[0] + i[1]] = 0xFF000000;
			i[1]++;
		}
		i[0]++;
	}
}

void	ft_draw_game(t_game *game, int sleep_time)
{
	mlx_clear_window(game->mlx->ptr, game->mlx->win->ptr);
	ft_clear_buffer(game->mlx->buffer);
	ft_draw_walls(game);
	if (ft_draw_pellets(game) == 0)
		ft_draw_exit(game);
	ft_draw_pacman(game);
	if (game->map->players->state != PLAYER_DYING && \
		game->map->players->state != PLAYER_DEAD)
		ft_draw_ghosts(game);
	mlx_put_image_to_window(game->mlx->ptr, game->mlx->win->ptr,
		game->mlx->buffer->ptr, 0, 96);
	ft_draw_info(game);
	if (sleep_time > 0)
		sleep(sleep_time);
}
