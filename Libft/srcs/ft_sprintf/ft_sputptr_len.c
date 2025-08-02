/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sputptr_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:55:07 by raamayri          #+#    #+#             */
/*   Updated: 2025/07/30 21:23:46 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_sprintf.h"

int	ft_sputptr_len(char *buf, void *ptr, int count)
{
	int	subcount;

	if (!ptr)
		return (ft_sputstr_len(buf, "(nil)", count));
	subcount = ft_sputstr_len(buf, "0x", count);
	subcount += ft_sputhex_len(buf, (unsigned long)ptr, count + subcount, 'x');
	return (subcount);
}
