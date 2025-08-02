/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sputhex_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:00:50 by raamayri          #+#    #+#             */
/*   Updated: 2025/07/29 19:03:57 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_sprintf.h"

int	ft_sputhex_len(char *buffer, unsigned long n, int count, char type)
{
	int		subcount;
	char	digit;

	subcount = 0;
	if (n == 0)
		return (ft_sputchar_len(buffer, '0', count + subcount));
	if (n >= 16)
		subcount += ft_sputhex_len(buffer, n / 16, count + subcount, type);
	digit = n % 16;
	if (digit <= 9)
		digit = digit + '0';
	else if (type == 'x')
		digit = digit - 10 + 'a';
	else
		digit = digit - 10 + 'A';
	return (subcount + ft_sputchar_len(buffer, digit, count + subcount));
}
