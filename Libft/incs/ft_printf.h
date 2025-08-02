/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:23:12 by raamayri          #+#    #+#             */
/*   Updated: 2025/06/26 17:58:28 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_putchar_len(char c);
int	ft_putstr_len(char *str);
int	ft_putunbr_len(unsigned int n);
int	ft_putnbr_len(int n);
int	ft_puthex_len(unsigned long n, char type);
int	ft_putptr_len(void *ptr);

#endif
