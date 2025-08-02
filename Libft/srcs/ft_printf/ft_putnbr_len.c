/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:00:14 by raamayri          #+#    #+#             */
/*   Updated: 2025/07/29 19:16:01 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

int	ft_putnbr_len(int n)
{
	char	digit;
	long	nb;
	int		subcount;

	nb = n;
	subcount = 0;
	if (nb < 0)
	{
		subcount += ft_putchar_len('-');
		nb = -nb;
	}
	if (nb > 9)
		subcount += ft_putnbr_len(nb / 10);
	digit = nb % 10 + 48;
	return (subcount + ft_putchar_len(digit));
}
