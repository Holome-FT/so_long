/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:37:58 by raamayri          #+#    #+#             */
/*   Updated: 2025/07/18 12:08:01 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/global.h"

static bool	ft_isvalid_width(t_map **maps, t_map *map, long long i[2])
{
	i[0] = 0;
	while (i[0] < map->wh[1])
		if ((long long)ft_strlen(map->data[i[0]++]) != map->wh[0])
			return (ft_free_maps(maps), false);
	if (map->wh[0] <= 2 || map->wh[1] <= 2 || \
		(map->wh[0] == 3 && map->wh[1] == 3))
		return (ft_free_maps(maps), false);
	if (map->wh[1] >= (long long)INT_MAX || map->wh[0] >= (long long)INT_MAX)
		return (ft_free_maps(maps), false);
	return (true);
}

static bool	ft_isvalid_borders(t_map **maps, t_map *map, long long i[2])
{
	i[0] = 0;
	while (map->data[i[0]])
	{
		i[1] = 0;
		while (map->data[i[0]][i[1]])
		{
			if ((i[0] == 0 || i[0] == map->wh[1] - 1) || \
				(i[1] == 0 || i[1] == map->wh[0] - 1))
			{
				if ((i[0] == 0 || i[0] == map->wh[1] - 1) && \
					(i[1] == 0 || i[1] == map->wh[0] - 1))
				{
					if (!ft_strchr("1", map->data[i[0]][i[1]]))
						return (ft_free_maps(maps), false);
				}
				else
					if (!ft_strchr("1T", map->data[i[0]][i[1]]))
						return (ft_free_maps(maps), false);
			}
			i[1]++;
		}
		i[0]++;
	}
	return (true);
}

static bool	ft_isvalid_elms(t_map **maps, t_map *map, long long i[2])
{
	long long	elms[128];

	i[0] = 0;
	while (i[0] < 128)
		elms[i[0]++] = 0;
	i[0] = 0;
	while (map->data[i[0]])
	{
		i[1] = 0;
		while (map->data[i[0]][i[1]])
		{
			if (!ft_strchr("01CBPMTE", map->data[i[0]][i[1]]))
				return (ft_free_maps(maps), false);
			elms[(int) map->data[i[0]][i[1]]]++;
			i[1]++;
		}
		i[0]++;
	}
	if (elms[(int) 'C'] + elms[(int) 'B'] == 0 || \
		elms[(int) 'P'] != 1 || \
		elms[(int) 'M'] < 1 || elms[(int) 'M'] > 4 || \
		elms[(int) 'T'] % 2 != 0 || \
		elms[(int) 'E'] != 1)
		return (ft_free_maps(maps), false);
	return (true);
}

static bool	ft_isvalid_teleporters(t_map **maps, t_map *map, long long i[2])
{
	i[0] = 0;
	while (map->data[i[0]])
	{
		i[1] = 0;
		while (map->data[i[0]][i[1]])
		{
			if (map->data[i[0]][i[1]] != 'T' && ++i[1] > 0)
				continue ;
			if ((i[0] > 0 && i[0] < map->wh[1] - 1 && \
				i[1] > 0 && i[1] < map->wh[0] - 1) || \
				(i[0] == 0 && map->data[map->wh[1] - 1][i[1]] != 'T') || \
				(i[0] == map->wh[1] - 1 && map->data[0][i[1]] != 'T') || \
				(i[1] == 0 && map->data[i[0]][map->wh[0] - 1] != 'T') || \
				(i[1] == map->wh[0] - 1 && map->data[i[0]][0] != 'T'))
				return (ft_free_maps(maps), false);
			i[1]++;
		}
		i[0]++;
	}
	return (true);
}

bool	ft_isvalid_maps(t_map **maps)
{
	t_map	*map;

	map = *maps;
	while (map)
	{
		if (!ft_isvalid_width(maps, map, (long long [2]){0, 0}))
			ft_error(ENOENT, "Map size is invalid.");
		if (!ft_isvalid_borders(maps, map, (long long [2]){0, 0}))
			ft_error(ENOENT, "Map is not surrounded by walls.");
		if (!ft_isvalid_elms(maps, map, (long long [2]){0, 0}) ||
			!ft_isvalid_teleporters(maps, map, (long long [2]){0, 0}))
			ft_error(ENOENT, "Map contains invalid elements.");
		map = map->next;
	}
	return (true);
}
