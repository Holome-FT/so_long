/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bfs_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 20:13:57 by raamayri          #+#    #+#             */
/*   Updated: 2025/08/02 19:20:53 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/global.h"

static int	ft_bfs_calc_queue(long long **mgc_nb, long long cur_xy[2],
	t_bfs *bfs, t_queue *queue)
{
	t_queue_node	*node;
	long long		mds_sq;

	node = ft_dequeue(queue);
	cur_xy[0] = node->x;
	cur_xy[1] = node->y;
	free(node);
	if (cur_xy[0] == mgc_nb[2][0] && cur_xy[1] == mgc_nb[2][1])
	{
		mgc_nb[0][2] = cur_xy[0];
		mgc_nb[0][3] = cur_xy[1];
		ft_find_next_step(mgc_nb[0], mgc_nb[1], bfs);
		ft_free_queue(queue);
		return (free(bfs->prt), free(bfs->vst), free(bfs), -1);
	}
	mds_sq = (cur_xy[0] - mgc_nb[2][0]) * (cur_xy[0] - mgc_nb[2][0]);
	mds_sq += (cur_xy[1] - mgc_nb[2][1]) * (cur_xy[1] - mgc_nb[2][1]);
	if (mgc_nb[0][4] == -1 || mds_sq < mgc_nb[0][4])
	{
		mgc_nb[0][4] = mds_sq;
		mgc_nb[0][2] = cur_xy[0];
		mgc_nb[0][3] = cur_xy[1];
	}
	return (0);
}

static void	ft_bfs_warp_queue(long long cur_xy[2],
	t_bfs *bfs, t_queue *queue)
{
	long long	wrp_xy[2];
	size_t		calc;

	if (bfs->map->data[cur_xy[1]][cur_xy[0]] == 'T')
	{
		wrp_xy[0] = cur_xy[0];
		wrp_xy[1] = cur_xy[1];
		if (cur_xy[0] == 0)
			wrp_xy[0] = bfs->map->wh[0] - 1;
		else if (cur_xy[0] == bfs->map->wh[0] - 1)
			wrp_xy[0] = 0;
		else if (cur_xy[1] == 0)
			wrp_xy[1] = bfs->map->wh[1] - 1;
		else if (cur_xy[1] == bfs->map->wh[1] - 1)
			wrp_xy[1] = 0;
		calc = wrp_xy[1] * bfs->map->wh[0] + wrp_xy[0];
		if (bfs->map->data[wrp_xy[1]][wrp_xy[0]] != '1' && !bfs->vst[calc])
		{
			bfs->vst[calc] = true;
			bfs->prt[calc].x = cur_xy[0];
			bfs->prt[calc].y = cur_xy[1];
			ft_enqueue(queue, wrp_xy);
		}
	}
}

static void	ft_bfs_neighbors_queue(long long cur_xy[2],
	t_bfs *bfs, t_queue *queue)
{
	long long	next_xy[2];
	size_t		calc;
	size_t		i;

	i = 0;
	while (i < 4)
	{
		next_xy[0] = cur_xy[0] + (int [4]){0, 0, -1, 1}[i];
		next_xy[1] = cur_xy[1] + (int [4]){-1, 1, 0, 0}[i];
		if (next_xy[0] < 0 || next_xy[0] >= bfs->map->wh[0] || \
			next_xy[1] < 0 || next_xy[1] >= bfs->map->wh[1])
		{
			i++;
			continue ;
		}
		calc = (size_t)next_xy[1] * bfs->map->wh[0] + next_xy[0];
		if (bfs->map->data[next_xy[1]][next_xy[0]] != '1' && !bfs->vst[calc])
		{
			bfs->vst[calc] = true;
			bfs->prt[calc].x = cur_xy[0];
			bfs->prt[calc].y = cur_xy[1];
			ft_enqueue(queue, next_xy);
		}
		i++;
	}
}

static int	ft_bfs_loop_queue(long long **mgc_nb, t_bfs *bfs, t_queue *queue)
{
	long long	cur_xy[2];
	size_t		i;

	i = 0;
	while (i < (size_t)bfs->map->wh[0] * bfs->map->wh[1])
	{
		bfs->vst[i] = false;
		bfs->prt[i].x = -1;
		bfs->prt[i].y = -1;
		i++;
	}
	ft_enqueue(queue, mgc_nb[0]);
	bfs->vst[(size_t)mgc_nb[0][1] * bfs->map->wh[0] + mgc_nb[0][0]] = true;
	while ((*queue).front)
	{
		if (ft_bfs_calc_queue(mgc_nb, cur_xy, bfs, queue) == -1)
			return (-1);
		ft_bfs_warp_queue(cur_xy, bfs, queue);
		ft_bfs_neighbors_queue(cur_xy, bfs, queue);
	}
	ft_find_next_step(mgc_nb[0], mgc_nb[1], bfs);
	ft_free_queue(queue);
	return (free(bfs->vst), free(bfs->prt), free(bfs), 0);
}

int	ft_bfs(t_map *map, long long new_xy[4], long long trg_xy[2])
{
	t_bfs		*bfs;
	t_queue		queue;
	long long	*mgc_nb[3];
	long long	clc_nb[5];

	if (new_xy[2] < 0 || new_xy[2] >= map->wh[0] || \
		new_xy[3] < 0 || new_xy[3] >= map->wh[1])
		return (-1);
	bfs = NULL;
	if (ft_init_bfs(&bfs, map) == -1)
		return (-1);
	queue.front = NULL;
	queue.rear = NULL;
	clc_nb[0] = new_xy[2];
	clc_nb[1] = new_xy[3];
	clc_nb[2] = clc_nb[0];
	clc_nb[3] = clc_nb[1];
	clc_nb[4] = -1;
	mgc_nb[0] = clc_nb;
	mgc_nb[1] = new_xy;
	mgc_nb[2] = trg_xy;
	ft_bfs_loop_queue(mgc_nb, bfs, &queue);
	return (0);
}
