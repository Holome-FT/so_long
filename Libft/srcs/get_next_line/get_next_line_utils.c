/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:55:07 by raamayri          #+#    #+#             */
/*   Updated: 2025/06/26 18:08:25 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/get_next_line.h"

int	ft_strlen_gnl(char *str, char c)
{
	int	len;

	len = 0;
	while (str && str[len] && str[len] != c)
		len++;
	return (len);
}

char	*ft_strjoin_gnl(char *lo, char *bf)
{
	char	*res;
	int		lolen;
	int		bflen;
	int		i;
	int		j;

	lolen = ft_strlen_gnl(lo, '\0');
	bflen = ft_strlen_gnl(bf, '\0');
	res = malloc(sizeof(char) * (lolen + bflen + 1));
	if (!res)
		return (free(lo), NULL);
	i = -1;
	while (++i < lolen)
		res[i] = lo[i];
	j = -1;
	while (++j < bflen)
		res[i + j] = bf[j];
	res[i + j] = '\0';
	return (free(lo), res);
}

char	*ft_strchr_gnl(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		return (&s[i]);
	return (NULL);
}
