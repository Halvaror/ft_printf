/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-b <alopez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 20:18:57 by alopez-b          #+#    #+#             */
/*   Updated: 2021/11/27 16:34:08 by alopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int ft_putchar(char c)
{
	write(1, &c, 1);
	return(1);
}

int ft_putstr(char *str)
{
	int i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n, int check)
{
	int	res;
	static int count = 0;

	if (check ==0)
		count = 0;
	if (n == -2147483648)
	{
		count += ft_putstr("-2");
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar('-');
		res = (n * -1);
		count++;
	}
	else
	{
		res = n;
	}
	if (res >= 10)
		ft_putnbr(res / 10, 1);
	count += ft_putchar((char)(res % 10 + 48));
	return(count);
}
	
int	ft_putnbr_hex(unsigned int nbr, char *base, int check)
{
	static int	count = 0;
	unsigned int hex;

	hex = 0;
	if (check == 0)
		count = 0;
	if (nbr >= 16)
		ft_putnbr_hex(nbr/16, base, 1);
	hex = nbr % 16;
	count += ft_putchar(base[hex]);
	return (count);
}
