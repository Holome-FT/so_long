/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:10:35 by raamayri          #+#    #+#             */
/*   Updated: 2025/06/28 21:11:26 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*cp_s1;
	unsigned char	*cp_s2;
	size_t			i;

	cp_s1 = (unsigned char *)s1;
	cp_s2 = (unsigned char *)s2;
	i = 0;
	while (cp_s1[i] && cp_s2[i] && cp_s1[i] == cp_s2[i])
		i++;
	return (cp_s1[i] - cp_s2[i]);
}
