/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:55:07 by raamayri          #+#    #+#             */
/*   Updated: 2025/07/29 19:15:57 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

int	ft_putptr_len(void *ptr)
{
	int	subcount;

	if (!ptr)
		return (ft_putstr_len("(nil)"));
	subcount = ft_putstr_len("0x");
	subcount += ft_puthex_len((unsigned long)ptr, 'x');
	return (subcount);
}
