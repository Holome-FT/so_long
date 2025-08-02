/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:55:07 by raamayri          #+#    #+#             */
/*   Updated: 2025/06/26 18:03:09 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char			*cp_s;
	unsigned char	cp_c;
	size_t			i;

	cp_s = (char *)s;
	cp_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		cp_s[i] = cp_c;
		i++;
	}
	return (s);
}
