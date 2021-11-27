/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-b <alopez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:18:13 by alopez-b          #+#    #+#             */
/*   Updated: 2021/11/27 16:28:52 by alopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int ft_ptraddress(void *ptr, char *base)
{
	//uintptr_t	address;
	int 		count;

	count = 0;
	//address = (uintptr_t)ptr;
	//printf("%lu\n", (uintptr_t)ptr);
	count += ft_putstr("0x");
	count += ft_putnbr_ptr((uintptr_t)ptr, base, 0);
	return (count);
}

int	ft_putnbr_ptr(unsigned long nbr, char *base, int check)
{
	static int	count = 0;
	unsigned long hex;

	hex = 0;
	if (check == 0)
		count = 0;
	if (nbr >= 16)
		ft_putnbr_ptr(nbr/16, base, 1);
	hex = nbr % 16;
	count += ft_putchar(base[hex]);
	return (count);
}


int	ft_putnbr_u(unsigned int n, int check)
{
	unsigned int	res;
	static int count = 0;

	if (check ==0)
		count = 0;
	if (n < 0)
	{
		ft_putchar('-');
		res = (n * -1);
		count++;
	}
	else
		res = n;
	if (res >= 10)
		ft_putnbr_u(res / 10, 1);
	count += ft_putchar((char)(res % 10 + 48));
	return(count);
}