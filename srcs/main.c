/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:45:36 by raamayri          #+#    #+#             */
/*   Updated: 2025/07/29 19:48:30 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/global.h"

static void	ft_init_flags(t_flags *flags)
{
	flags->debug = false;
	flags->force = false;
	flags->loop = false;
}

static size_t	ft_count_maps(t_map *maps)
{
	t_map	*cp_maps;
	size_t	i;

	i = 0;
	if (!maps)
		return (i);
	cp_maps = maps;
	while (cp_maps)
	{
		i++;
		cp_maps = cp_maps->next;
	}
	return (i);
}

static void	ft_game_switch(t_map **maps, t_flags *flags)
{
	size_t	mapslen;

	mapslen = ft_count_maps(*maps);
	if (mapslen == 0)
		ft_error(EINVAL, "Need at least one map.");
	else if (flags->force)
		ft_load_game(maps, flags);
	else if (flags->loop)
	{
		if (ft_isvalid_maps(maps) && ft_isfinishable_maps(maps))
			ft_load_game(maps, flags);
	}
	else
	{
		if (mapslen != 1)
		{
			ft_free_maps(maps);
			ft_error(E2BIG, "Use --loop for multiple maps.");
		}
		else if (ft_isvalid_maps(maps) && ft_isfinishable_maps(maps))
			ft_load_game(maps, flags);
	}
}

int	main(int argc, char **argv)
{
	t_map	*maps;
	t_flags	flags;
	size_t	i;

	maps = NULL;
	ft_init_flags(&flags);
	i = 1;
	if ((size_t)argc == i)
		ft_error(EINVAL, "Not enough arguments. Use --help for usage.");
	while (i < (size_t)argc)
	{
		if (ft_strncmp(argv[i], "-", 1) == 0)
			ft_flag_switch(&maps, &flags, &argv[i][1]);
		else if (ft_addnew_map(&maps, argv[i]) == -1)
			ft_error(ENOENT, "Invalid map provided.");
		i++;
	}
	ft_game_switch(&maps, &flags);
	return (EXIT_SUCCESS);
}
