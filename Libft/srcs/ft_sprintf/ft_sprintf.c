/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:55:07 by raamayri          #+#    #+#             */
/*   Updated: 2025/07/30 21:23:24 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_sprintf.h"

static int	ft_switch(char *buf, const char *str, int count, va_list args)
{
	if (str[0] == 'c')
		return (ft_sputchar_len(buf, va_arg(args, int), count));
	if (str[0] == 's')
		return (ft_sputstr_len(buf, va_arg(args, char *), count));
	if (str[0] == 'p')
		return (ft_sputptr_len(buf, va_arg(args, void *), count));
	if (str[0] == 'd' || str[0] == 'i')
		return (ft_sputnbr_len(buf, va_arg(args, int), count));
	if (str[0] == 'u')
		return (ft_sputunbr_len(buf, va_arg(args, unsigned int), count));
	if (str[0] == 'x' || str[0] == 'X')
		return (ft_sputhex_len(buf, va_arg(args, unsigned int), count, str[0]));
	if (str[0] == '%')
		return (ft_sputchar_len(buf, '%', count));
	return (0);
}

int	ft_sprintf(char *buffer, const char *str, ...)
{
	va_list	args;
	int		count;
	int		i;

	if (!buffer || !str)
		return (-1);
	va_start(args, str);
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			count += ft_switch(buffer, &str[++i], count, args);
		else
			count += ft_sputchar_len(buffer, str[i], count);
		if (str[i])
			i++;
	}
	buffer[count] = '\0';
	return (va_end(args), count);
}
