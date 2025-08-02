/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:55:07 by raamayri          #+#    #+#             */
/*   Updated: 2025/06/26 18:05:13 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*cp_s;
	unsigned char	cp_c;
	size_t			i;

	cp_s = (char *)s;
	cp_c = (unsigned char)c;
	i = 0;
	while (cp_s[i])
	{
		if (cp_s[i] == cp_c)
			return (&cp_s[i]);
		i++;
	}
	if (cp_s[i] == cp_c)
		return (&cp_s[i]);
	return (NULL);
}
