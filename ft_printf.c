/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-b <alopez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 21:05:40 by alopez-b          #+#    #+#             */
/*   Updated: 2021/11/23 21:46:49 by alopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	conversions(int count, const char *format, va_list ap,  int i)
{
	if (format[i] == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (format[i] == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (format[i] == 'd')
		count += ft_putnbr(va_arg(ap, int), 0);
	else if (format[i] == '%')
	{
		write(1, "%",1);
		count++;
	}
	else if (format[i] == 'u')
		count += ft_putnbr(va_arg(ap, int), 0);
	else if (format[i] == 'x')
		{
			count += ft_putnbr_hex(va_arg(ap, int), UPPER_HEX, 0);
			printf("int: %u\n", va_arg(ap, int));
		}	
	else if (format[i] == 'X')
		count += ft_putnbr_hex(va_arg(ap, unsigned int), LOWER_HEX, 0);
	return (count);
}

int ft_printf(const char *format, ...)
{
	va_list ap;
	int i;
	int	count;
	
	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count = conversions(count, format, ap, i++);
		}
		write(1, &format[i++], 1);
		count++;
	}
	//printf("i: %d count:%d", i, count);
	va_end(ap);
	return (count);
}

#if DEBUG
int	main(int argc, char **argv)
{
	
	(void)argc;
	(void)argv;
	ft_printf("Hexadecimal: %x\n", -1);
}
#endif