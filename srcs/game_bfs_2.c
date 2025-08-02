/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bfs_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 20:13:57 by raamayri          #+#    #+#             */
/*   Updated: 2025/08/01 22:31:52 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/global.h"

t_queue_node	*ft_new_queue_node(long long x, long long y)
{
	t_queue_node	*node;

	node = ft_calloc(1, sizeof(t_queue_node));
	if (!node)
		return (NULL);
	node->x = x;
	node->y = y;
	node->next = NULL;
	return (node);
}

void	ft_enqueue(t_queue *queue, long long xy[2])
{
	t_queue_node	*node;

	node = ft_new_queue_node(xy[0], xy[1]);
	if (!node)
		return ;
	if (!queue->rear)
	{
		queue->front = node;
		queue->rear = node;
	}
	else
	{
		queue->rear->next = node;
		queue->rear = node;
	}
}

t_queue_node	*ft_dequeue(t_queue *queue)
{
	t_queue_node	*node;

	if (!queue->front)
		return (NULL);
	node = queue->front;
	queue->front = queue->front->next;
	if (!queue->front)
		queue->rear = NULL;
	return (node);
}

void	ft_free_queue(t_queue *queue)
{
	t_queue_node	*temp;

	while (queue->front)
	{
		temp = queue->front;
		queue->front = queue->front->next;
		free(temp);
	}
}

void	ft_find_next_step(long long clc_nb[5],
	long long *result_xy, t_bfs *bfs)
{
	long long	path_xy[2];
	long long	next_path_xy[2];
	size_t		calc;

	if (clc_nb[0] == clc_nb[2] && clc_nb[1] == clc_nb[3])
	{
		result_xy[0] = clc_nb[2];
		result_xy[1] = clc_nb[3];
		return ;
	}
	path_xy[0] = clc_nb[2];
	path_xy[1] = clc_nb[3];
	calc = (size_t)path_xy[1] * bfs->map->wh[0] + path_xy[0];
	while (bfs->prt[calc].x != clc_nb[0] || \
		bfs->prt[calc].y != clc_nb[1])
	{
		next_path_xy[0] = bfs->prt[calc].x;
		next_path_xy[1] = bfs->prt[calc].y;
		path_xy[0] = next_path_xy[0];
		path_xy[1] = next_path_xy[1];
		calc = (size_t)path_xy[1] * bfs->map->wh[0] + path_xy[0];
	}
	result_xy[0] = path_xy[0];
	result_xy[1] = path_xy[1];
}
