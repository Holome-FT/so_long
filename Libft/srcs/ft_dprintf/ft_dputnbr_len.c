/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dputnbr_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:00:14 by raamayri          #+#    #+#             */
/*   Updated: 2025/07/29 19:17:21 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_dprintf.h"

int	ft_dputnbr_len(int fd, int n)
{
	char	digit;
	long	nb;
	int		subcount;

	nb = n;
	subcount = 0;
	if (nb < 0)
	{
		subcount += ft_dputchar_len(fd, '-');
		nb = -nb;
	}
	if (nb > 9)
		subcount += ft_dputnbr_len(fd, nb / 10);
	digit = nb % 10 + 48;
	return (subcount + ft_dputchar_len(fd, digit));
}
