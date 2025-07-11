/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuni.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsafad <malsafad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:47:06 by malsafad          #+#    #+#             */
/*   Updated: 2025/07/11 17:27:50 by malsafad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuni(unsigned int n)
{
	int	count;

	count = 0;
	if (n <= 9)
		count += ft_putchar(n + '0');
	else
	{
		count += ft_putuni(n / 10);
		count += ft_putuni(n % 10);
	}
	return (count);
}
