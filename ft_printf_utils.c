/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-b <alopez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 20:18:57 by alopez-b          #+#    #+#             */
/*   Updated: 2021/11/17 21:36:48 by alopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int ft_putchar(char c)
{
	if (!c)
	{
		write(1, "(null)", 6);
		return (6);
	}
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
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	res;
	static int count = 0;
	
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
		ft_putnbr(res / 10);
	count += ft_putchar((char)(res % 10 + 48));
	return(count);
	}