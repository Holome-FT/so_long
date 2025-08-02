/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dputptr_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:55:07 by raamayri          #+#    #+#             */
/*   Updated: 2025/07/29 19:16:29 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_dprintf.h"

int	ft_dputptr_len(int fd, void *ptr)
{
	int	subcount;

	if (!ptr)
		return (ft_dputstr_len(fd, "(nil)"));
	subcount = ft_dputstr_len(fd, "0x");
	subcount += ft_dputhex_len(fd, (unsigned long)ptr, 'x');
	return (subcount);
}
