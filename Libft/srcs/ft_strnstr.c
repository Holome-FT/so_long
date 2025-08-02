/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:55:07 by raamayri          #+#    #+#             */
/*   Updated: 2025/06/26 18:07:01 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	char	*cp_haystack;
	size_t	needlelen;
	size_t	i;
	size_t	j;

	cp_haystack = (char *)haystack;
	needlelen = ft_strlen(needle);
	i = 0;
	if (needlelen == 0)
		return (cp_haystack);
	while (cp_haystack[i])
	{
		j = 0;
		while (cp_haystack[i + j] && needle[j] && i + j < n)
		{
			if (needle[j] != cp_haystack[i + j])
				break ;
			if (j + 1 == needlelen)
				return (&cp_haystack[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
