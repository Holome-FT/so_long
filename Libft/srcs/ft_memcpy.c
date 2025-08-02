/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:55:07 by raamayri          #+#    #+#             */
/*   Updated: 2025/06/26 18:02:48 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*cp_dest;
	char	*cp_src;
	size_t	i;

	cp_dest = (char *)dest;
	cp_src = (char *)src;
	if (!cp_dest && !cp_src)
		return (dest);
	i = 0;
	while (i < n)
	{
		cp_dest[i] = cp_src[i];
		i++;
	}
	return (dest);
}
