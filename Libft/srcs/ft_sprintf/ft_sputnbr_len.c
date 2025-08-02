/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sputnbr_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:00:14 by raamayri          #+#    #+#             */
/*   Updated: 2025/07/29 19:23:00 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_sprintf.h"

int	ft_sputnbr_len(char *buffer, int n, int count)
{
	char	digit;
	long	nb;
	int		subcount;

	nb = n;
	subcount = 0;
	if (nb < 0)
	{
		subcount += ft_sputchar_len(buffer, '-', count + subcount);
		nb = -nb;
	}
	if (nb > 9)
		subcount += ft_sputnbr_len(buffer, nb / 10, count + subcount);
	digit = nb % 10 + 48;
	return (subcount + ft_sputchar_len(buffer, digit, count + subcount));
}
