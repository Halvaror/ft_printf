/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-b <alopez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 21:05:40 by alopez-b          #+#    #+#             */
/*   Updated: 2021/11/17 21:43:27 by alopez-b         ###   ########.fr       */
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
		count += ft_putnbr(va_arg(ap, int));
	else if (format[i] == '%')
	{
		write(1, "%",1);
		count++;
	}
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
	printf("i: %d count:%d", i, count);
	va_end(ap);
	return (--count);
}

#if DEBUG
int	main(int argc, char **argv)
{
	int i;
	i = 0;
	(void)argc;
	i = ft_printf("hola %s me gusta %s y la %c emmanuel me la come %d%%\n", argv[1], argv[2], 'a', 1000);
	printf ("count: %d", i);
}
#endif