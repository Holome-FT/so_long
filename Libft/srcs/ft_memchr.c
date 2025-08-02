/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:55:07 by raamayri          #+#    #+#             */
/*   Updated: 2025/06/26 18:02:28 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cp_s;
	unsigned char	cp_c;
	size_t			i;

	cp_s = (unsigned char *)s;
	cp_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (cp_s[i] == cp_c)
			return (&cp_s[i]);
		i++;
	}
	return (NULL);
}
