/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:04:56 by raamayri          #+#    #+#             */
/*   Updated: 2025/07/14 17:26:25 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/global.h"

void	ft_free_array(void ***array)
{
	size_t	i;

	if (!array || !*array)
		return ;
	i = 0;
	while ((*array)[i])
		free((*array)[i++]);
	free(*array);
	*array = NULL;
}

void	ft_free_players(t_player **players)
{
	t_player	*cr_player;
	t_player	*tp_player;

	if (!players || !*players)
		return ;
	cr_player = *players;
	while (cr_player)
	{
		tp_player = cr_player->next;
		free(cr_player);
		cr_player = tp_player;
	}
	*players = NULL;
}

void	ft_free_ghosts(t_ghost **ghosts)
{
	t_ghost	*cr_ghost;
	t_ghost	*tp_ghost;

	if (!ghosts || !*ghosts)
		return ;
	cr_ghost = *ghosts;
	while (cr_ghost)
	{
		tp_ghost = cr_ghost->next;
		free(cr_ghost);
		cr_ghost = tp_ghost;
	}
	*ghosts = NULL;
}

void	ft_free_pellets(t_pellet **pellets)
{
	t_pellet	*cr_pellet;
	t_pellet	*tp_pellet;

	if (!pellets || !*pellets)
		return ;
	cr_pellet = *pellets;
	while (cr_pellet)
	{
		tp_pellet = cr_pellet->next;
		free(cr_pellet);
		cr_pellet = tp_pellet;
	}
	*pellets = NULL;
}

void	ft_free_maps(t_map **maps)
{
	t_map	*cr_maps;
	t_map	*tp_maps;

	if (!maps || !*maps)
		return ;
	cr_maps = *maps;
	while (cr_maps)
	{
		tp_maps = cr_maps->next;
		if (cr_maps->fd != -1)
		{
			close(cr_maps->fd);
			cr_maps->fd = -1;
		}
		ft_free_array((void ***)&cr_maps->data);
		ft_free_players(&cr_maps->players);
		ft_free_ghosts(&cr_maps->ghosts);
		ft_free_pellets(&cr_maps->pellets);
		free(cr_maps);
		cr_maps = tp_maps;
	}
	*maps = NULL;
}
