/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:53:19 by raamayri          #+#    #+#             */
/*   Updated: 2025/06/26 17:54:47 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

int	ft_isspace(int c)
{
	unsigned char	c_cp;

	c_cp = (unsigned char)c;
	if ((c_cp >= 9 && c_cp <= 13) || c_cp == 32)
		return (1);
	return (0);
}
