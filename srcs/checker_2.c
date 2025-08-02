/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:38:07 by raamayri          #+#    #+#             */
/*   Updated: 2025/07/16 00:18:07 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/global.h"

bool	**ft_alloc_mask(t_map *map)
{
	long long	xy[2];
	bool		**mask;

	mask = ft_calloc(map->wh[1] + 1, sizeof(bool *));
	if (!mask)
		return (NULL);
	xy[1] = 0;
	while (xy[1] < map->wh[1])
	{
		mask[xy[1]] = ft_calloc(map->wh[0] + 1, sizeof(bool));
		if (!mask[xy[1]])
			return (ft_free_array((void ***)&mask), NULL);
		xy[1]++;
	}
	return (mask);
}

static void	ft_find_player(t_map *map, long long p_xy[2])
{
	long long	xy[2];

	xy[1] = 0;
	while (xy[1] < map->wh[1])
	{
		xy[0] = 0;
		while (xy[0] < map->wh[0])
		{
			if (map->data[xy[1]][xy[0]] == 'P')
			{
				p_xy[0] = xy[0];
				p_xy[1] = xy[1];
				return ;
			}
			xy[0]++;
		}
		xy[1]++;
	}
}

static void	ft_dfs(t_map *map, bool **visited,
	long long xy[2], long long elms[128])
{
	if (visited[xy[1]][xy[0]] || ft_strchr("1", map->data[xy[1]][xy[0]]))
		return ;
	visited[xy[1]][xy[0]] = true;
	if (map->data[xy[1]][xy[0]] == 'E')
		elms[(int) 'E']++;
	else if (map->data[xy[1]][xy[0]] == 'C')
		elms[(int) 'C']++;
	else if (map->data[xy[1]][xy[0]] == 'B')
		elms[(int) 'B']++;
	else if (map->data[xy[1]][xy[0]] == 'T')
	{
		if (xy[0] == 0)
			ft_dfs(map, visited, (long long [2]){map->wh[0] - 2, xy[1]}, elms);
		else if (xy[0] == map->wh[0] - 1)
			ft_dfs(map, visited, (long long [2]){1, xy[1]}, elms);
		else if (xy[1] == 0)
			ft_dfs(map, visited, (long long [2]){xy[0], map->wh[1] - 2}, elms);
		else if (xy[1] == map->wh[1] - 1)
			ft_dfs(map, visited, (long long [2]){xy[0], 1}, elms);
		return ;
	}
	ft_dfs(map, visited, (long long [2]){xy[0] + 1, xy[1]}, elms);
	ft_dfs(map, visited, (long long [2]){xy[0] - 1, xy[1]}, elms);
	ft_dfs(map, visited, (long long [2]){xy[0], xy[1] + 1}, elms);
	ft_dfs(map, visited, (long long [2]){xy[0], xy[1] - 1}, elms);
}

static bool	ft_browse_map(t_map **maps, t_map *map)
{
	t_pellet		*cp_pellets;
	bool			**mask;
	long long		p_xy[2];
	long long		elms[128];
	long long		i;

	mask = ft_alloc_mask(map);
	if (!mask)
		return (ft_free_maps(maps), false);
	ft_find_player(map, p_xy);
	i = 0;
	while (i < 128)
		elms[i++] = 0;
	ft_dfs(map, mask, p_xy, elms);
	ft_free_array((void ***)&mask);
	i = 0;
	cp_pellets = map->pellets;
	while (cp_pellets)
	{
		i++;
		cp_pellets = cp_pellets->next;
	}
	if (elms[(int) 'C'] + elms[(int) 'B'] != i || elms[(int) 'E'] != 1)
		return (ft_free_maps(maps), false);
	return (true);
}

bool	ft_isfinishable_maps(t_map **maps)
{
	t_map	*map;

	map = *maps;
	while (map)
	{
		if (!ft_browse_map(maps, map))
			ft_error(ENOENT, "Map is not finishable.");
		map = map->next;
	}
	return (true);
}
