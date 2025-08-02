/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:55:07 by raamayri          #+#    #+#             */
/*   Updated: 2025/07/13 18:26:45 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_dprintf.h"

static int	ft_switch(int fd, const char *str, va_list args)
{
	if (str[0] == 'c')
		return (ft_dputchar_len(fd, va_arg(args, int)));
	if (str[0] == 's')
		return (ft_dputstr_len(fd, va_arg(args, char *)));
	if (str[0] == 'p')
		return (ft_dputptr_len(fd, va_arg(args, void *)));
	if (str[0] == 'd' || str[0] == 'i')
		return (ft_dputnbr_len(fd, va_arg(args, int)));
	if (str[0] == 'u')
		return (ft_dputunbr_len(fd, va_arg(args, unsigned int)));
	if (str[0] == 'x' || str[0] == 'X')
		return (ft_dputhex_len(fd, va_arg(args, unsigned int), str[0]));
	if (str[0] == '%')
		return (ft_dputchar_len(fd, '%'));
	return (0);
}

int	ft_dprintf(int fd, const char *str, ...)
{
	va_list	args;
	int		count;
	int		i;

	if (fd < 0 || !str)
		return (-1);
	va_start(args, str);
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			count += ft_switch(fd, &str[++i], args);
		else
			count += ft_dputchar_len(fd, str[i]);
		if (str[i])
			i++;
	}
	return (va_end(args), count);
}
