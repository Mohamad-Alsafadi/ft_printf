/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsafad <malsafad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:26:55 by malsafad          #+#    #+#             */
/*   Updated: 2025/07/11 17:27:04 by malsafad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long num, const char *base)
{
	int	count;

	count = 0;
	if (num >= 16)
		count += ft_puthex(num / 16, base);
	count += ft_putchar(base[num % 16]);
	return (count);
}
