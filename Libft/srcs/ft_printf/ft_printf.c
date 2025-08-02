/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:55:07 by raamayri          #+#    #+#             */
/*   Updated: 2025/06/28 18:56:53 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

static int	ft_switch(const char *str, va_list args)
{
	if (str[0] == 'c')
		return (ft_putchar_len(va_arg(args, int)));
	if (str[0] == 's')
		return (ft_putstr_len(va_arg(args, char *)));
	if (str[0] == 'p')
		return (ft_putptr_len(va_arg(args, void *)));
	if (str[0] == 'd' || str[0] == 'i')
		return (ft_putnbr_len(va_arg(args, int)));
	if (str[0] == 'u')
		return (ft_putunbr_len(va_arg(args, unsigned int)));
	if (str[0] == 'x' || str[0] == 'X')
		return (ft_puthex_len(va_arg(args, unsigned int), str[0]));
	if (str[0] == '%')
		return (ft_putchar_len('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		i;

	if (!str)
		return (-1);
	va_start(args, str);
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			count += ft_switch(&str[++i], args);
		else
			count += ft_putchar_len(str[i]);
		if (str[i])
			i++;
	}
	return (va_end(args), count);
}
