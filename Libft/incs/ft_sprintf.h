/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:23:12 by raamayri          #+#    #+#             */
/*   Updated: 2025/07/29 18:53:10 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SPRINTF_H

# define FT_SPRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_sprintf(char *buffer, const char *str, ...);
int	ft_sputchar_len(char *buffer, char c, int count);
int	ft_sputstr_len(char *buffer, char *str, int count);
int	ft_sputunbr_len(char *buffer, unsigned int n, int count);
int	ft_sputnbr_len(char *buffer, int n, int count);
int	ft_sputhex_len(char *buffer, unsigned long n, int count, char type);
int	ft_sputptr_len(char *buffer, void *ptr, int count);

#endif
