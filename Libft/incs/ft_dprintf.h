/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:23:12 by raamayri          #+#    #+#             */
/*   Updated: 2025/07/13 18:16:35 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DPRINTF_H

# define FT_DPRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_dprintf(int fd, const char *str, ...);
int	ft_dputchar_len(int fd, char c);
int	ft_dputstr_len(int fd, char *str);
int	ft_dputunbr_len(int fd, unsigned int n);
int	ft_dputnbr_len(int fd, int n);
int	ft_dputhex_len(int fd, unsigned long n, char type);
int	ft_dputptr_len(int fd, void *ptr);

#endif
