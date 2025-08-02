/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:07:00 by raamayri          #+#    #+#             */
/*   Updated: 2025/07/13 18:29:53 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/global.h"

void	ft_error(int id, const char *msg)
{
	int	fd;

	fd = STDERR_FILENO;
	if (errno == 0 && id != 0)
		errno = id;
	ft_dprintf(fd, "┌ Error %d: %s\n", errno, strerror(errno));
	if (id < 10)
		ft_dprintf(fd, "└───────── %s\n", msg);
	else if (id < 100)
		ft_dprintf(fd, "└────────── %s\n", msg);
	else
		ft_dprintf(fd, "└─────────── %s\n", msg);
	exit(EXIT_FAILURE);
}
