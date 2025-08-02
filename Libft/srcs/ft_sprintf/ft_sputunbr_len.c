/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sputunbr_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:59:32 by raamayri          #+#    #+#             */
/*   Updated: 2025/07/29 19:23:12 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_sprintf.h"

int	ft_sputunbr_len(char *buffer, unsigned int n, int count)
{
	int		subcount;
	char	digit;

	subcount = 0;
	if (n > 9)
		subcount += ft_sputunbr_len(buffer, n / 10, count + subcount);
	digit = n % 10 + 48;
	return (subcount + ft_sputchar_len(buffer, digit, count + subcount));
}
