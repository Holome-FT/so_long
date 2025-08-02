/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:58:31 by raamayri          #+#    #+#             */
/*   Updated: 2025/07/29 19:15:46 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

int	ft_putstr_len(char *str)
{
	int	subcount;

	subcount = 0;
	if (!str)
		return (ft_putstr_len("(null)"));
	while (str[subcount])
		subcount += ft_putchar_len(str[subcount]);
	return (subcount);
}
