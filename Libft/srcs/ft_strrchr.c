/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:55:07 by raamayri          #+#    #+#             */
/*   Updated: 2025/06/26 18:07:17 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*cp_s;
	unsigned char	cp_c;
	int				i;

	cp_s = (char *)s;
	cp_c = (unsigned char)c;
	i = ft_strlen(cp_s);
	while (i > 0)
	{
		if (cp_s[i] == cp_c)
			return (&cp_s[i]);
		i--;
	}
	if (cp_s[i] == cp_c)
		return (&cp_s[i]);
	return (NULL);
}
