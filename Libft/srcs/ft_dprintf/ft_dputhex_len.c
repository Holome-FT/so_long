/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dputhex_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:00:50 by raamayri          #+#    #+#             */
/*   Updated: 2025/07/29 19:16:23 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_dprintf.h"

int	ft_dputhex_len(int fd, unsigned long n, char type)
{
	int		subcount;
	char	digit;

	if (n == 0)
		return (ft_dputchar_len(fd, '0'));
	subcount = 0;
	if (n >= 16)
		subcount += ft_dputhex_len(fd, n / 16, type);
	digit = n % 16;
	if (digit <= 9)
		digit = digit + '0';
	else if (type == 'x')
		digit = digit - 10 + 'a';
	else
		digit = digit - 10 + 'A';
	return (subcount + ft_dputchar_len(fd, digit));
}
