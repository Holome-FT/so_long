/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:55:07 by raamayri          #+#    #+#             */
/*   Updated: 2025/06/26 18:02:59 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*cp_dest;
	char	*cp_src;
	size_t	i;

	cp_dest = (char *)dest;
	cp_src = (char *)src;
	if (n == 0)
		return (dest);
	if (cp_dest <= cp_src)
		return (ft_memcpy(dest, src, n));
	i = n - 1;
	while (i > 0)
	{
		cp_dest[i] = cp_src[i];
		i--;
	}
	cp_dest[i] = cp_src[i];
	return (dest);
}
