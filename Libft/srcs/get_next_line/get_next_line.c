/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:55:07 by raamayri          #+#    #+#             */
/*   Updated: 2025/06/26 18:08:33 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/get_next_line.h"

char	*ft_get_line_gnl(char *lo)
{
	char	*ln;
	int		lnlen;
	int		i;

	if (!lo)
		return (NULL);
	lnlen = ft_strlen_gnl(lo, '\n');
	if (lo[lnlen] == '\n')
		lnlen++;
	ln = malloc(sizeof(char) * (lnlen + 1));
	if (!ln)
		return (free(lo), NULL);
	i = -1;
	while (++i < lnlen)
		ln[i] = lo[i];
	ln[i] = '\0';
	return (ln);
}

char	*ft_update_leftover_gnl(char *lo)
{
	char	*new_lo;
	int		i;
	int		j;

	if (!lo)
		return (NULL);
	i = ft_strlen_gnl(lo, '\n');
	if (lo[i] == '\n')
		i++;
	if (!lo[i])
		return (free(lo), NULL);
	new_lo = malloc(sizeof(char) * (ft_strlen_gnl(lo, '\0') - i + 1));
	if (!new_lo)
		return (free(lo), NULL);
	j = -1;
	while (lo[i + (++j)])
		new_lo[j] = lo[i + j];
	new_lo[j] = '\0';
	return (free(lo), new_lo);
}

char	*ft_read_filedescriptor_gnl(int fd, char *lo)
{
	char	*bf;
	int		br;

	bf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!bf)
		return (NULL);
	br = 1;
	while (!ft_strchr_gnl(lo, '\n') && br != 0)
	{
		br = read(fd, bf, BUFFER_SIZE);
		if (br == -1)
			return (free(lo), free(bf), NULL);
		bf[br] = '\0';
		lo = ft_strjoin_gnl(lo, bf);
		if (!lo)
			return (free(bf), NULL);
	}
	return (free(bf), lo);
}

char	*get_next_line(int fd)
{
	static char	*lo[1024];
	char		*ln;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	lo[fd] = ft_read_filedescriptor_gnl(fd, lo[fd]);
	if (!lo[fd])
		return (NULL);
	ln = ft_get_line_gnl(lo[fd]);
	if (!ln)
		return ((lo[fd] = NULL), NULL);
	lo[fd] = ft_update_leftover_gnl(lo[fd]);
	if (!ln[0])
		return (free(ln), NULL);
	return (ln);
}
