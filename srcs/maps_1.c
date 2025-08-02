/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:06:03 by raamayri          #+#    #+#             */
/*   Updated: 2025/07/07 18:51:13 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/global.h"

static char	**ft_clean_lines(char **lines)
{
	char	*cp_line;
	size_t	linelen;
	size_t	i;

	if (!lines)
		return (NULL);
	i = 0;
	while (lines[i])
	{
		linelen = ft_strlen(lines[i]);
		if (linelen > 0 && lines[i][linelen - 1] == '\n')
			linelen--;
		cp_line = ft_calloc(linelen + 1, sizeof(char));
		if (!cp_line)
			return (ft_free_array((void ***)&lines), NULL);
		ft_memcpy(cp_line, lines[i], linelen);
		free(lines[i]);
		lines[i] = cp_line;
		i++;
	}
	return (lines);
}

static char	**ft_read_map(int fd)
{
	char	**lines[2];
	char	*line;
	size_t	i[2];

	lines[0] = NULL;
	line = get_next_line(fd);
	i[0] = 0;
	while (line)
	{
		lines[1] = ft_calloc(i[0] + 2, sizeof(char *));
		if (!lines[1])
			return (free(line), ft_free_array((void ***)&lines), NULL);
		i[1] = 0;
		while (lines[0] && i[1] < i[0])
		{
			lines[1][i[1]] = lines[0][i[1]];
			i[1]++;
		}
		lines[1][i[0]++] = line;
		if (lines[0])
			free(lines[0]);
		lines[0] = lines[1];
		line = get_next_line(fd);
	}
	return (ft_clean_lines(lines[0]));
}

int	ft_addnew_map(t_map **maps, const char *path)
{
	t_map	*cp_maps;
	t_map	*map;
	size_t	pathlen;

	pathlen = ft_strlen(path);
	if (pathlen < 5 || ft_strcmp(&path[pathlen - 4], ".ber") != 0)
		return (ft_free_maps(maps), -1);
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (ft_free_maps(maps), -1);
	map->fd = open(path, O_RDONLY);
	if (map->fd == -1)
		return (ft_free_maps(maps), free(map), -1);
	map->data = ft_read_map(map->fd);
	if (!map->data)
		return (close(map->fd), ft_free_maps(maps), free(map), -1);
	if (ft_init_map(map) == -1)
		return (close(map->fd), ft_free_maps(maps), free(map), -1);
	map->next = NULL;
	cp_maps = *maps;
	if (!cp_maps)
		return ((*maps = map), (map->prev = NULL), 0);
	while (cp_maps->next)
		cp_maps = cp_maps->next;
	return ((cp_maps->next = map), (map->prev = cp_maps), 0);
}
