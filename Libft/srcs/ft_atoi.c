/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:55:07 by raamayri          #+#    #+#             */
/*   Updated: 2025/06/26 17:55:09 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	int		res;
	char	sign;

	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	res = 0;
	sign = '\0';
	if (nptr[i] == 43 || nptr[i] == 45)
		sign = nptr[i++];
	while (ft_isdigit(nptr[i]))
		res = res * 10 + (nptr[i++] - 48);
	if (sign == 45)
		res = -res;
	return (res);
}
