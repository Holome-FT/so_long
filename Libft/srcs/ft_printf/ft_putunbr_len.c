/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:59:32 by raamayri          #+#    #+#             */
/*   Updated: 2025/07/29 19:15:51 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

int	ft_putunbr_len(unsigned int n)
{
	int		subcount;
	char	digit;

	subcount = 0;
	if (n > 9)
		subcount += ft_putunbr_len(n / 10);
	digit = n % 10 + 48;
	return (subcount + ft_putchar_len(digit));
}
