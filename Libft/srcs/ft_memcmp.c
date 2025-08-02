/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:55:07 by raamayri          #+#    #+#             */
/*   Updated: 2025/06/26 18:02:38 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*cp_s1;
	unsigned char	*cp_s2;
	size_t			i;

	cp_s1 = (unsigned char *)s1;
	cp_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (cp_s1[i] != cp_s2[i])
			return (cp_s1[i] - cp_s2[i]);
		i++;
	}
	return (0);
}
