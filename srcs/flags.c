/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:06:38 by raamayri          #+#    #+#             */
/*   Updated: 2025/07/15 21:45:38 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/global.h"

static void	ft_error_flag(t_map **maps, const char *msg)
{
	ft_free_maps(maps);
	ft_error(EINVAL, msg);
}

static void	ft_flag_help(t_map **maps)
{
	ft_printf(
		"so_long — This project is a small 2D game.\n"
		"\n"
		"Usage:\n"
		"  ./so_long [options] <map> [<map> ...]\n"
		"\n"
		"Options:\n"
		"  -h, --help    Show this help message and exit\n"
		"  -l, --loop    Loop through multiple maps endlessly\n"
		"  -f, --force   Force start and bypass map validation checks\n"
		"  --debug       Enables developer mode\n"
		"\n"
		"Arguments:\n"
		"  <map>         Path to a .ber map file to play with\n"
		);
	ft_free_maps(maps);
	exit(EXIT_SUCCESS);
}

static void	ft_fullflag_switch(t_map **maps, t_flags *flags, const char *flag)
{
	if (ft_strlen(flag) == 0)
		ft_error_flag(maps, "Lone double dash provided.");
	else if (ft_strcmp(flag, "help") == 0)
		ft_flag_help(maps);
	else if (ft_strcmp(flag, "loop") == 0)
		flags->loop = true;
	else if (ft_strcmp(flag, "force") == 0)
		flags->force = true;
	else if (ft_strcmp(flag, "debug") == 0)
		flags->debug = true;
	else
		ft_error_flag(maps, "Invalid flag provided.");
}

void	ft_flag_switch(t_map **maps, t_flags *flags, const char *flag)
{
	size_t	i;

	if (ft_strlen(flag) == 0)
		ft_error_flag(maps, "Lone dash provided.");
	else if (ft_strncmp(flag, "-", 1) == 0)
		ft_fullflag_switch(maps, flags, &flag[1]);
	else
	{
		i = 0;
		while (flag[i])
		{
			if (flag[i] == 'h')
				ft_flag_help(maps);
			else if (flag[i] == 'l')
				flags->loop = true;
			else if (flag[i] == 'f')
				flags->force = true;
			else
				ft_error_flag(maps, "Invalid flag provided.");
			i++;
		}
	}
}
