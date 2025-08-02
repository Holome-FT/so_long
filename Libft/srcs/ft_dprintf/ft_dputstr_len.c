/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dputstr_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:58:31 by raamayri          #+#    #+#             */
/*   Updated: 2025/07/29 19:16:34 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_dprintf.h"

int	ft_dputstr_len(int fd, char *str)
{
	int	subcount;

	subcount = 0;
	if (!str)
		return (ft_dputstr_len(fd, "(null)"));
	while (str[subcount])
		subcount += ft_dputchar_len(fd, str[subcount]);
	return (subcount);
}
