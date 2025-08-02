/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:00:50 by raamayri          #+#    #+#             */
/*   Updated: 2025/07/29 19:16:06 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

int	ft_puthex_len(unsigned long n, char type)
{
	int		subcount;
	char	digit;

	if (n == 0)
		return (ft_putchar_len('0'));
	subcount = 0;
	if (n >= 16)
		subcount += ft_puthex_len(n / 16, type);
	digit = n % 16;
	if (digit <= 9)
		digit = digit + '0';
	else if (type == 'x')
		digit = digit - 10 + 'a';
	else
		digit = digit - 10 + 'A';
	return (subcount + ft_putchar_len(digit));
}
