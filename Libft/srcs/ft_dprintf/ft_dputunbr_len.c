/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dputunbr_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:59:32 by raamayri          #+#    #+#             */
/*   Updated: 2025/07/29 19:16:38 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_dprintf.h"

int	ft_dputunbr_len(int fd, unsigned int n)
{
	int		subcount;
	char	digit;

	subcount = 0;
	if (n > 9)
		subcount += ft_dputunbr_len(fd, n / 10);
	digit = n % 10 + 48;
	return (subcount + ft_dputchar_len(fd, digit));
}
