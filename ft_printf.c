/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsafad <malsafad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:57:39 by malsafad          #+#    #+#             */
/*   Updated: 2025/07/11 17:26:34 by malsafad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char spec, va_list ap)
{
	int	count;

	count = 0;
	if (spec == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (spec == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (spec == 'p')
		count += ft_putptr(va_arg(ap, void *));
	else if (spec == 'd' || spec == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (spec == 'u')
		count += ft_putuni(va_arg(ap, unsigned int));
	else if (spec == 'x')
		count += ft_puthex(va_arg(ap, unsigned int), HEX_LOW_BASE);
	else if (spec == 'X')
		count += ft_puthex(va_arg(ap, unsigned int), HEX_UPP_BASE);
	else if (spec == '%')
		count += ft_putchar('%');
	else
		count += write(1, &spec, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			count += ft_format(*(++format), ap);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}
