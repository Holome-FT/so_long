/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sputstr_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:58:31 by raamayri          #+#    #+#             */
/*   Updated: 2025/07/29 19:09:08 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_sprintf.h"

int	ft_sputstr_len(char *buffer, char *str, int count)
{
	int	subcount;

	subcount = 0;
	if (!str)
		return (ft_sputstr_len(buffer, "(null)", count));
	while (str[subcount])
		subcount += ft_sputchar_len(buffer, str[subcount], count + subcount);
	return (subcount);
}
