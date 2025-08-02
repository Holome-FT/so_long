/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sputchar_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:55:02 by raamayri          #+#    #+#             */
/*   Updated: 2025/07/29 18:50:32 by raamayri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_sprintf.h"

int	ft_sputchar_len(char *buffer, char c, int count)
{
	buffer[count] = c;
	return (1);
}
